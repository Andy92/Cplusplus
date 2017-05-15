#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Profession.cpp"
#include "Race.cpp"
#include "Creature.cpp"
#include "Environment.cpp"
#include "Room.cpp"
#include "Direction.cpp"






#ifndef MAIN_HPP
#define MAIN_HPP

namespace lab3 {
	class Main {
public:
		void combat1v1(Character *first, Creature *second);

		void Game();
		
};
}

#endif