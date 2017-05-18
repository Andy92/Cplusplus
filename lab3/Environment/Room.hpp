#include "Direction.hpp"

#ifndef ROOM_HPP
#define ROOM_HPP

 
	class Environment;
	class Room {
	private:
		std::vector<Direction> dirs;
		std::vector<Creature*> creatures;
		Environment *e;
		int id;
	public:
		

		Room(Environment *e, std::vector<Creature*> creatures);
		void setDirections(std::vector<Direction> dirs);
		std::vector<Direction> getDirections();
		void setID();
		int getID();
		bool setEnv();
		std::string getEnvDesc();
	}; 

#endif