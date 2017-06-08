#include "Room.hpp"

	std::vector<Room*> Environment::getRooms() {
		return this->rooms;
	}
	
	Environment::Environment(std::string descr, int id) {
		this->description = descr;
		this->id = id;
	}
	Environment::~Environment() {
		/*
		for(int i=0;i<this->rooms.size();++i) {
			delete this->rooms[i];
		}
		*/
	}
	
	void Environment::setRoom(std::vector<Room*> rooms) {
		this->rooms = rooms;
	}

	std::string Environment::getDesc() {
		return this->description;
	}

	int Environment::getID() {
		return this->id;
	}

	Room::Room(Environment *e, std::vector<Creature*> creatures, std::string description) {	
		this->creatures = creatures;
		this->e = e;
		setID();	// Set the id of the room.
		setEnv();
		this->desc = description;
	}

	Room::~Room() {
		// delete all creatures
		for(int i=0;i<this->creatures.size();++i) {
			delete this->creatures[i];
		}
		
		// delete all directions
		for(int i=0;i<this->dirs.size();++i) {
			delete this->dirs[i];
		}
		// delete all enviroments
		if((this->getID() % 1000) == 0) {
			delete this->e;
		}
<<<<<<< HEAD
=======
		// delete shopkeeper

			delete this->sk;

>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		
		
	}

	void Room::setID() {
		std::vector<Room*> rooms = this->e->getRooms();
<<<<<<< HEAD
		this->id = this->e->getID() * maxRooms + rooms.size();
=======
		this->id = this->e->getID() * MAXROOM + rooms.size();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	}

	// Environment will have 1000 room maximum.
	bool Room::setEnv() {
		std::vector<Room*> rooms = this->e->getRooms();
		// If there is already a room with same id in list, update it.
		for(unsigned int i=0;i<rooms.size();++i) {
			if(this->id == rooms.at(i)->id) {
				rooms.at(i) = this;
				this->e->setRoom(rooms);
				return true;
			}
		} 
		rooms.push_back(this);
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

	std::string Room::getRoomDesc() {
		return this->desc;
	}
	
	void Room::setDirections(std::vector<Direction*> dirs) {
		this->dirs = dirs;
		setEnv();
	}

	std::vector<Direction*> Room::getDirections() {
		return this->dirs;
	}
	
	std::vector<Creature*> Room::getCreatureList() {
		return this->creatures;
	}
	Shopkeeper* Room::getShopkeeper() {
		return this->sk;
	}
<<<<<<< HEAD
=======
	/* Not needed anymore
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	Creature* Room::getChar() {
		return this->mainChar;
	}

	void Room::setChar(Creature* newChar) {
		this->mainChar = newChar;
	}
<<<<<<< HEAD
	void Room::setShopkeeper(Shopkeeper* sk) {
		this->sk = sk;
	}
=======
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	
	bool Room::remChar() {
		if(this->mainChar != NULL){
			this->mainChar = NULL;
			return true;
		} else {
			return false;
		}
	}
<<<<<<< HEAD
=======
	*/

	void Room::setShopkeeper(Shopkeeper* sk) {
		this->sk = sk;
	}
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
