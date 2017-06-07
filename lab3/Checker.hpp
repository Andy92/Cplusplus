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
		bool tax = false;

	public:
		Checker(Character* character, Room* curroom, std::vector<Room*> room);
		~Checker();
		void moveChar(Room* toRoom);
		Room* getRoom() const;
		Character* getChar() const;

		Quest* getQuest() const;
		bool getTax() const;
		void payTax();
	};

#endif

