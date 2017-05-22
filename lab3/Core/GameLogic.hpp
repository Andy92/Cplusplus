#include "../Checker.hpp"
#include "../Environment/Room.hpp"
#include <algorithm>

#ifndef GameLogic_HPP
#define GameLogic_HPP

class GameLogic {
	private:
		static std::vector<std::string> Races;
		static std::vector<std::string> Professions;
		Checker* ch = 0;
	public:
		Character* charCreation();
		GameLogic(Checker* ch);
		bool changeDir(std::string newDir);
		void ExecCmd(int parsedInt);	

};
#endif