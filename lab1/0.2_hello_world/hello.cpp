#include <iostream>
#include "hello.h"
#include <cstdlib>

void hello (const char * ch, int count) {
	std::cout << "Hello, ";
	for(int i=1;i<=count;++i)
  std::cout << ch << " ";
	std::cout << "\n";
}

std::pair<const char *, int> parse_args (int argc, char * argv[]) {
  int count = 1;
  if (argc < 1) {
	std::cerr << "Error! Something went wrong.\n";
   } else if (argc == 1) {
    	return std::make_pair ("World!", count);
   } else if (argc == 2) {
    	return std::make_pair (argv[1], count);
   } else if (argc == 3) {
	
       	count = std::atoi(argv[2]);
       	return std::make_pair (argv[1], count);
   } else {
     	std::cerr << "Too many arguments!\n";
   }
  
}
