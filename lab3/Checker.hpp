#include "Environment/Room.hpp"
#include "Characters/Character.hpp"

using namespace std;

#ifndef CHECKER_HPP
#define CHECKER_HPP

	class Checker {
	public:
		Character* character;
		Room* curroom;
		Checker(Character* character, Room* curroom);
	};

#endif

