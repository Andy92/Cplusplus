#include "Room.hpp"
#include "Character.hpp"

using namespace std;

#ifndef CHECKER_HPP
#define CHECKER_HPP

namespace lab3 {
	class Checker {
	public:
		Character* character;
		Room* curroom;
		checker(Character* character, Room* curroom);
	};
}

#endif

