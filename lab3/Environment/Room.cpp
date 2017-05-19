#include "Room.hpp"

	Room::Room(Environment *e, std::vector<Creature*> creatures) {	
		this->creatures = creatures;
		this->e = e;
		setID();	// Set the id of the room.
		setEnv();
	}

	void Room::setID() {
		std::vector<Room> rooms = this->e->getRooms();
		this->id = rooms.size();
	}

	bool Room::setEnv() {
		std::vector<Room> rooms = this->e->getRooms();
		// If there is already a room with same id in list, update it.
		for(int i=0;i<rooms.size();++i) {
			if(this->id == rooms.at(i).id) {
				rooms.at(i) = *this;
				this->e->setRoom(rooms);
				return true;
			}
		} 
		rooms.push_back(*this);
		this->e->setRoom(rooms);
		// TODO: check if there are memory leaks here?
		return true;
		
	}
	

	int Room::getID() {
		return this->id;
	}

	std::string Room::getEnvDesc() {
		return e->getDesc();
	}
	
	void Room::setDirections(std::vector<Direction> dirs) {
		this->dirs = dirs;
		setEnv();
	}

	std::vector<Direction> Room::getDirections() {
		return this->dirs;
	}
	
	Creature* Room::getChar() {
		return this->mainChar;
	}

	void Room::setChar(Creature* newChar) {
		this->mainChar = newChar;
	}
	
	bool Room::remChar() {
		if(this->mainChar != NULL){
			this->mainChar = NULL;
			return true;
		} else {
			return false;
		}
	}
