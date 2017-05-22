#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Race.hpp"
#include "Profession.hpp"

#ifndef CREATURE_HPP
#define CREATURE_HPP
class Creature {
public:
	Race* r;
	int hp = 100;
	int str = 10;
	Creature();
	Creature(Race* race);
	std::string stats();
	std::string toString();
	void hit(int dmg);
};
class Character : public Creature {	// Creature being a lower order base class for example
public:
	Profession* p = 0;
	//Room* rum;
	Character(Race* race, Profession* profession);
	std::string toString();
};


#endif