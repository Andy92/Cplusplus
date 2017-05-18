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

Human::Human(std::string identifier) : Race(identifier) {
	rhp = 1.1;
	rstr = 1.1;


}

Orc::Orc(std::string identifier) : Race(identifier) {
	rhp = 1.3;
	rstr = 1.4;
  
}