#include "../Characters/Creature.hpp"
#include "Direction.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#ifndef ROOM_HPP
#define ROOM_HPP

 	class Environment;
	class Room {
	private:
		std::vector<Direction> dirs;
		std::vector<Creature*> creatures;
		Environment *e;
		int id;
		Creature* mainChar;
	public:
		

		Room(Environment *e, std::vector<Creature*> creatures);
		void setDirections(std::vector<Direction> dirs);
		std::vector<Direction> getDirections();
		void setID();
		int getID();
		bool setEnv();
		std::string getEnvDesc();
		Creature* getChar();
		void setChar(Creature* newChar);
		bool remChar();
	}; 
	class Environment {
	private:
		std::string description = "";
		std::vector<Room> rooms;
	public:
		Environment(std::string descr);
		void setRoom(std::vector<Room> rooms);
		std::string getDesc();
		std::vector<Room> getRooms();
	}; 
#endif
