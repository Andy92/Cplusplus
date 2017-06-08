#include "../Checker.hpp"
#include "../Environment/Room.hpp"
//#include "../Quest.hpp"
#include <algorithm>

#ifndef GameLogic_HPP
#define GameLogic_HPP
#define CHARAC this->ch->getChar()
#define ROOM this->ch->getRoom()

class GameLogic {
	private:
		static std::vector<std::string> Races;
		static std::vector<std::string> Professions;
		Checker* ch = 0;
	public:
		Character* charCreation();
		GameLogic(Checker* ch);
		~GameLogic();
		bool changeDir(std::string newDir);
		void ExecCmd(int parsedInt);
		int takeInt();	
		void fightingMode();
		void backpackMode();
		void inventoryMode();
		void shopkeeperMode();
		void combat1v1(Character* first, Creature* second);
		void getDirections();
		void sellMode();
		void outputQuestObj();
		void talking();
		void castleTax();
		void Special();
		void findGodSword();
};
#endif
