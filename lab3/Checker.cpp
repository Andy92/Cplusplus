#include "Checker.hpp"

<<<<<<< HEAD
Checker::Checker(Character* character, Room* curroom, std::vector<Room*> room, std::vector<Environment*> envs) {
		this->character = character;
		this->curroom = curroom;
		this->envVec = envs;
=======
Checker::Checker(Character* character, Room* curroom, std::vector<Room*> room) {
		this->character = character;
		this->curroom = curroom;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		//this->roomVec = room;
		this->quest = new Quest(room);
	}
Checker::~Checker() {
<<<<<<< HEAD
	delete this->quest;
	delete this->character;
	/*
	for(int i = 0; i < this->envVec.size(); ++i) {
		delete this->envVec.at(i);
	}
	*/
}	
bool Checker::moveChar(Room* toRoom) {
	if(this->curroom->remChar()) {
		toRoom->setChar(this->character);
		this->curroom = toRoom;
		std::cout << "Environment: " << this->curroom->getEnvDesc() << std::endl;
		std::cout << this->curroom->getRoomDesc() << std::endl;
		return true;
	} else {
		return false;
	}
=======
	delete this->character;
	delete this->quest;
}
void Checker::moveChar(Room* toRoom) {
	this->curroom = toRoom;
	std::cout << "Environment: " << this->curroom->getEnvDesc() << std::endl;
	std::cout << this->curroom->getRoomDesc() << std::endl;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
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