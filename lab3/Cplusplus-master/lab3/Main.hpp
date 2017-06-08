#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Characters/Creature.hpp"
#include "Environment/Environment.hpp"
#include "Checker.hpp"
#include "Core/Parser.hpp"
#include "Core/GameLogic.hpp"


#ifndef MAIN_HPP
#define MAIN_HPP

#define E "East"
#define W "West"
#define N "North"
#define S "South"

	class Main {
private:
	static std::vector<Room*> roomVec;
	Checker* ch = 0;
	GameLogic* gl = 0;
public:
		void Init();
		void Game();
		
};


#endif
