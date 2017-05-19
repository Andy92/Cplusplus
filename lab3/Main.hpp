#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Characters/Creature.cpp"
#include "Environment/Environment.cpp"
#include "Environment/Room.cpp"
#include "Environment/Direction.cpp"
#include "Checker.cpp"
#include "Core/Parser.cpp"
#include "Core/GameLogic.cpp"





#ifndef MAIN_HPP
#define MAIN_HPP

	class Main {
private:
	Checker* ch = 0;
	GameLogic* gl = 0;
public:
		void combat1v1(Character *first, Creature *second);
		void Init();
		void Game();
		
};


#endif
