#include "Checker.hpp"

Checker::Checker(Character* character, Room* curroom, std::vector<Room*> room) {
		this->character = character;
		this->curroom = curroom;
		//this->roomVec = room;
		this->quest = new Quest(room);
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

Character* Checker::getChar() {
	return this->character;
}

Quest* Checker::getQuest() {
	return this->quest;
}

bool Checker::getTax() {
	return this->tax;
}

void Checker::payTax() {
	this->tax = true;
}