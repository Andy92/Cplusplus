#include "test_entry.hpp"
#include "natch.hpp"

#include <algorithm>
#include <csignal>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <unistd.h>


int REAL_STDOUT_FD = -1;

void
unexpected_sigaction (int signal, siginfo_t * si, void * arg)
{
  char buffer[1024] {};

  int diagnostic_len = std::snprintf (buffer, 1024,
    "ERROR:LOGIC your implementation crashed (signal: %d, error: \"%s\")\n",
    signal, strsignal (signal)
  );

  int bytes_written = 0, write_ret;
  int tries = 8;
  
  while ((write_ret = write (REAL_STDOUT_FD, buffer + bytes_written, diagnostic_len - bytes_written)) > 0) {
    bytes_written += write_ret;  

    if (bytes_written == diagnostic_len)
      break;

    if (--tries == 0)
      break;
  }

  std::quick_exit (0);
}

void
register_sigcatcher (int sig, void (*fptr)(int, siginfo_t *, void *)) {
  struct sigaction sact;

  std::fill_n (reinterpret_cast<char*> (&sact), 0, sizeof sact);

  sigemptyset (&sact.sa_mask);
  
  sact.sa_sigaction = fptr;
  sact.sa_flags     = SA_SIGINFO | SA_ONSTACK | SA_RESTART;

  sigaction (sig, &sact, NULL);
}

int main () {
  if ((REAL_STDOUT_FD = dup (fileno (stdout))) < 0) {
    std::printf ("ERROR:TEST unable to `dup` stdout\n");
    return 0;
  }

  natch::basic_environment be {std::cin, std::cout};

  register_sigcatcher (SIGSEGV, &unexpected_sigaction);
  register_sigcatcher (SIGFPE,  &unexpected_sigaction);

  try {
    test_entry (be);

  } catch (natch::test_error  const& e) { be.test_error  (e.what ());
  } catch (natch::fatal_error const& e) { be.fatal_error (e.what ());
  } catch (natch::logic_error const& e) { be.logic_error (e.what ()); 
  } catch (std::bad_alloc& e)     { be.logic_error ("std::bad_alloc ()");
  } catch (std::exception& e) {
    be.logic_error (std::string ("unexpected exception, std::exception::what () = '") + e.what () + "'!");
  } catch (...) {
    be.logic_error ("unknown exception, aborting!");
  }
}
