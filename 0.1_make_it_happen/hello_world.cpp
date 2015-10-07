#include <iostream>

class hello_world
{
int hello (int argv, char* argc[]) {
	std::cout << "Hello, ";
	if (argv == 1) {
		std::cout << "World!";
}
	for (int i = 1; i < argv; i += 1) {
		std::cout << argc[i] << " ";
}
	std::cout << "\n";
}
};
