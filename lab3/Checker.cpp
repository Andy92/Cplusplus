#include "Checker.hpp"

Checker::Checker(Character* character, Room* curroom) {
		this->character = character;
		this->curroom = curroom;
	}

bool Checker::moveChar(Room* toRoom) {
	if(this->curroom->remChar()) {
		toRoom->setChar(this->character);
		this->curroom = toRoom;
		return true;
	} else {
		return false;
	}
}

Room* Checker::getRoom() {
	return this->curroom;
}
