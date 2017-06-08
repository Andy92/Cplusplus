#include <utility>
#include "hello.h"
#include "hello.cpp"

using namespace std;

int main (int argc, char* argv[]) {
  std::pair<const char *, int> p = parse_args (argc , argv);

  if (p.second != -1)
    hello (p.first, p.second);
}
