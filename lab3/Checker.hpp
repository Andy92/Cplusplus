#include "Environment/Room.hpp"
#include "Characters/Character.hpp"

using namespace std;

#ifndef CHECKER_HPP
#define CHECKER_HPP

	class Checker {
	private:
		Character* character;
		Room* curroom;
	public:
		Checker(Character* character, Room* curroom);
		bool moveChar(Room* toRoom);
		Room* getRoom();
		Character* getChar();
	};

#endif

