#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Characters/Creature.hpp"
#include "Environment/Environment.hpp"
<<<<<<< HEAD
//#include "Environment/Room.cpp"
//#include "Environment/Direction.cpp"
#include "Checker.hpp"
#include "Core/Parser.hpp"
#include "Core/GameLogic.hpp"
//#include "Quest.hpp"



=======
#include "Checker.hpp"
#include "Core/Parser.hpp"
#include "Core/GameLogic.hpp"
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965


#ifndef MAIN_HPP
#define MAIN_HPP

#define E "East"
#define W "West"
#define N "North"
#define S "South"

	class Main {
private:
<<<<<<< HEAD
	std::vector<Environment*> envVec;
=======
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	std::vector<Room*> roomVec;
	Checker* ch = 0;
	GameLogic* gl = 0;
public:
		void Init();
		void Game();
		
};


#endif
