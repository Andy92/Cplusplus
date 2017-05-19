#include "GameLogic.hpp"



GameLogic::GameLogic(Checker* ch) {
	this->ch = ch;
}

bool GameLogic::east() {
	Room* oldRoom = this->ch->getRoom();
	std::vector<Direction> dirs = oldRoom->getDirections();
	for(int i =0; i < dirs.size() ;++i) {
		if(dirs.at(i).getName().compare("east")) {
			Room* newRoom = dirs.at(i).getToRoom();
			return this->ch->moveChar(newRoom);
		}
	}
	return false;
}

void GameLogic::ExecCmd(int parsedInt) {
	switch(parsedInt) {
		case 0 : std::cout << "go west" << std::endl; 
			break; // go west
		case 1 : std::cout << "go east" << std::endl;
			this->east(); // go east
			break;
		case 666 : std::cout << "You are at roomID: " << this->ch->getRoom()->getID() << std::endl;
			break;
		default : std::cout << "default" << std::endl;
			break;
	}
}
