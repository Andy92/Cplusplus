#include "Checker.hpp"

Checker::Checker(Character* character, Room* curroom, std::vector<Room*> room) {
		this->character = character;
		this->curroom = curroom;
		//this->roomVec = room;
		this->quest = new Quest(room);
	}
Checker::~Checker() {
	delete this->character;
	delete this->quest;
}
void Checker::moveChar(Room* toRoom) {
	this->curroom = toRoom;
	std::cout << "Environment: " << this->curroom->getEnvDesc() << std::endl;
	std::cout << this->curroom->getRoomDesc() << std::endl;
}

Room* Checker::getRoom() const {
	return this->curroom;
}

Character* Checker::getChar() const {
	return this->character;
}

Quest* Checker::getQuest() const {
	return this->quest;
}

bool Checker::getTax() const {
	return this->tax;
}

void Checker::payTax() {
	this->tax = true;
}