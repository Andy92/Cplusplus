#include "Room.hpp"
using namespace std;
using namespace lab3;

	Room::Room(Environment *e, vector<Creature*> creatures) {	
		this->creatures = creatures;
		this->e = e;
		setID();	// Set the id of the room.
		setEnv();
	}

	void Room::setID() {
		vector<Room> rooms = this->e->getRooms();
		this->id = rooms.size();
	}

	bool Room::setEnv() {
		vector<Room> rooms = this->e->getRooms();
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
		return true;
		
	}
	

	int Room::getID() {
		return this->id;
	}

	string Room::getEnvDesc() {
		return e->getDesc();
	}
	
	void Room::setDirections(vector<Direction> dirs) {
		this->dirs = dirs;
		setEnv();
	}

	vector<Direction> Room::getDirections() {
		return this->dirs;
	}
	