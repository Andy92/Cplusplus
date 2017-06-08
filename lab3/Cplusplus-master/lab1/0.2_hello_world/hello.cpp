#include <iostream>
#include "hello.h"
#include <cstdlib>

void hello (const char * ch, int count) {
	std::cout << "Hello, ";
	if (count != 0){
		for(int i=1;i<=count-1;++i)
  			std::cout << ch << " ";
		std::cout << ch << "!\n";
	} else {
	std::cout << "\n";
	}
}

std::pair<const char *, int> parse_args (int argc, char * argv[]) {
int count = 1;
  if (argc < 1) {
	std::cerr << "Error!!";
	return std::make_pair (argv[1], -1);
   } else if (argc == 1) {
    	return std::make_pair ("world", count);
   } else if (argc == 2) {
    	return std::make_pair (argv[1], count);
   } else if (argc == 3) {
	    if (* argv[2] != 48) {
       		count = std::atoi(argv[2]);
		    if (count <= 0) {
			    std::cerr << "2nd argument must be an integral greater than zero!\n";
		        return std::make_pair (argv[1], -1);
		    } else {
		    return std::make_pair (argv[1], count);
		    }
	    } else {
       	return std::make_pair (argv[1], -1);
	    }
    } else {
     	std::cerr << "Too many arguments!\n";
	return std::make_pair (argv[1], -1);
    }
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
