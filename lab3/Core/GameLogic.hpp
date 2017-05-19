#include "../Checker.hpp"
#include "../Environment/Room.hpp"

#ifndef GameLogic_HPP
#define GameLogic_HPP

class GameLogic {
	private:
		Checker* ch = 0;
	public:
		GameLogic(Checker* ch);
		bool east();
		void ExecCmd(int parsedInt);	

};
#endif
