#include "Environment/Room.hpp"
#include "Characters/Character.hpp"
#include "Quest.hpp"

#ifndef CHECKER_HPP
#define CHECKER_HPP


	class Checker {
	private:
<<<<<<< HEAD
		std::vector<Environment*> envVec;
=======
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		Character* character = 0;
		Room* curroom = 0;
		Quest* quest = 0;
		bool tax = false;

	public:
<<<<<<< HEAD
		Checker(Character* character, Room* curroom, std::vector<Room*> room, std::vector<Environment*> envs);
		~Checker();
		bool moveChar(Room* toRoom);
=======
		Checker(Character* character, Room* curroom, std::vector<Room*> room);
		~Checker();
		void moveChar(Room* toRoom);
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		Room* getRoom() const;
		Character* getChar() const;

		Quest* getQuest() const;
		bool getTax() const;
		void payTax();
	};

#endif

