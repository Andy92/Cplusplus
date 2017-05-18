#include "Environment.hpp"



	Environment::Environment(std::string descr) {
		this->description = descr;
	}
	
	void Environment::setRoom(std::vector<Room> rooms) {
		this->rooms = rooms;
	}

	std::string Environment::getDesc() {
		return this->description;
	}

	std::vector<Room> Environment::getRooms() {
		return this->rooms;
	}