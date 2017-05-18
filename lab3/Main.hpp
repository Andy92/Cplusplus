#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Characters/Creature.cpp"
#include "Environment/Environment.cpp"
#include "Environment/Room.cpp"
#include "Environment/Direction.cpp"
#include "Checker.hpp"
#include "Core/Parser.cpp"






#ifndef MAIN_HPP
#define MAIN_HPP

	class Main {
public:
		void combat1v1(Character *first, Creature *second);
		void Init();
		void Game();
		
};


#endif