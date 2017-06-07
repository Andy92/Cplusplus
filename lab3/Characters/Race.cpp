#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Race.hpp"

Human::Human() {
	rhp = 1.1;
	rstr = 1.1;
}

std::string Human::toString() {
	return std::string("Humanoid");
} 

Orc::Orc() {
	rhp = 1.3;
	rstr = 1.4;
  
}

std::string Orc::toString() {
	return std::string("Orc");
} 

Bandit::Bandit() {
	rhp = 0.9;
	rstr = 0.9;
  
}

std::string Bandit::toString() {
	return std::string("Bandit");
} 

Knight::Knight() {
	rhp = 2.7;
	rstr = 2.7;
  
}


std::string Knight::toString() {
	return std::string("Knight");
} 

Dragon::Dragon() {
	rhp = 6.5;
	rstr = 4.5;
}

std::string Dragon::toString() {
	return std::string("Dragon");
} 