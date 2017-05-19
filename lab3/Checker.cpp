Checker::Checker(Character* char, Room* curroom) {
		this->character = char;
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
