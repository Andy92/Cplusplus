#include "Environment.hpp"


using namespace lab3;

	Environment::Environment(string descr) {
		this->description = descr;
	}
	
	void Environment::setRoom(vector<Room> rooms) {
		this->rooms = rooms;
	}

	string Environment::getDesc() {
		return this->description;
	}

	vector<Room> Environment::getRooms() {
		return this->rooms;
	}