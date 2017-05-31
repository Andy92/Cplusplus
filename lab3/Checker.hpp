#include "Environment/Room.hpp"
#include "Characters/Character.hpp"
#include "Quest.hpp"

#ifndef CHECKER_HPP
#define CHECKER_HPP


	class Checker {
	private:
		Character* character = 0;
		Room* curroom = 0;
		Quest* quest = 0;

	public:
		//std::vector<Room*> roomVec;
		//Quest* quest;
		Checker(Character* character, Room* curroom, std::vector<Room*> room);
		bool moveChar(Room* toRoom);
		Room* getRoom();
		Character* getChar();

		Quest* getQuest();
		//bool checkQuest();
	};

#endif

