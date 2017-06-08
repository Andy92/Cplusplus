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
		for (auto it = this->creatures.begin(); it != this->creatures.end(); ++it)
	{
		delete *it;
	}
	this->creatures.clear();

		
		
		// delete all directions
		for(int i=0;i<this->dirs.size();++i) {
			delete this->dirs[i];
		}
		this->dirs.clear();
		// delete all enviroments
		if((this->getID() % MAXROOM) == 0) {
			delete this->e;
		}
		// delete shopkeeper

			delete this->sk;

		
		
	}
	int Room::event() const {
		std::cout << std::endl << "you are breathing in ashes that are leftover in \nthe air of the dragons attack and you feel your chest hurting";
		return 0;
	}
	ForestRoom::ForestRoom(Environment *e, std::vector<Creature*> creatures, std::string description) : Room(e, creatures, description) {
	}

	int ForestRoom::event() const {
		std::cout << std::endl << "you can feel the fresh air of the forest making you stronger \nand you are regenerating from the damage caused by the ash";
		return 2;
	}
	int TownRoom::event() const {
		std::cout << std::endl << "The ashes are intensifying inside town and \nyour chest starts hurting even more";
		return 3;
	}
	TownRoom::TownRoom(Environment *e, std::vector<Creature*> creatures, std::string description) : Room(e, creatures, description) {
	}


	void Room::setID() {
		std::vector<Room*> rooms = this->e->getRooms();
		this->id = this->e->getID() * MAXROOM + rooms.size();
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
	/* Not needed anymore
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
	*/

	void Room::setShopkeeper(Shopkeeper* sk) {
		this->sk = sk;
	}
