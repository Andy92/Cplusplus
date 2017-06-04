#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Race.hpp"
Race::Race(std::string identifier){
	this->id = identifier;
}
std::string Race::toString() {
	return this->id;
} 

Human::Human() : Race("Human") {
	rhp = 1.1;
	rstr = 1.1;


}

Orc::Orc() : Race("Orc") {
	rhp = 1.3;
	rstr = 1.4;
  
}

Bandit::Bandit() : Race("Bandit") {
	rhp = 0.9;
	rstr = 0.9;
  
}

Knight::Knight() : Race("Knight") {
	rhp = 2.7;
	rstr = 2.7;
  
}

Dragon::Dragon() : Race("Dragon") {
	rhp = 6.5;
	rstr = 4.5;
}