#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


class A {
	A(int a) {
		std::cout << a << std::endl;
	}
};

int main() {
	int *a = new int(5);
	std::cout << a << std::endl;
}


