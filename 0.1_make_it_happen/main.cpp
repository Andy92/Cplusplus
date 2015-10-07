#include <iostream>
#include "hello_world.h"

using namespace std;

int hello (char* w) {
	std::cout << "Hello, " << w << " \n";
};

int main(int argv, char* argc[])
{
	if (argv > 1) {
		hello(argc);
} else {
	hello("World!");
}
};



