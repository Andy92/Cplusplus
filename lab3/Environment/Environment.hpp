#include "Room.hpp"

#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
 
	class Environment {

		std::string description = "";
		std::vector<Room> rooms;
	public:
		Environment(std::string descr);
		void setRoom(std::vector<Room> rooms);
		std::string getDesc();
		std::vector<Room> getRooms();
	}; 
#endif