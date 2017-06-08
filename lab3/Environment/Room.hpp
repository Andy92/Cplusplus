#include "../Characters/Creature.hpp"
#include "Direction.hpp"
#include "../Characters/Shopkeeper.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#ifndef ROOM_HPP
#define ROOM_HPP

// Maximum number of rooms
<<<<<<< HEAD
#define maxRooms 1000
=======
#define MAXROOM 1000
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965

 	class Environment;
	class Room {
	private:
		std::vector<Direction*> dirs;
		std::vector<Creature*> creatures;
		std::string desc = "";
		Environment *e = 0;
		int id;
<<<<<<< HEAD
		Creature* mainChar = 0;
=======
		//Creature* mainChar = 0;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		Shopkeeper* sk = 0;
	public:
		Room(Environment *e, std::vector<Creature*> creatures, std::string description);
		~Room();
		void setDirections(std::vector<Direction*> dirs);
		std::vector<Direction*> getDirections();
		void setID();
		int getID();
		bool setEnv();
		std::string getEnvDesc();
		std::string getRoomDesc();
<<<<<<< HEAD
		Creature* getChar();
		void setChar(Creature* newChar);
		bool remChar();
=======
		//Creature* getChar();
		//void setChar(Creature* newChar);
		//bool remChar();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		std::vector<Creature*> getCreatureList();
		Shopkeeper* getShopkeeper();
		void setShopkeeper(Shopkeeper* sk);
	}; 
	class Environment {
	private:
		std::string description = "";
		std::vector<Room*> rooms;
		int id;
	public:
		Environment(std::string descr, int id);
		~Environment();
		void setRoom(std::vector<Room*> rooms);
		std::string getDesc();
		std::vector<Room*> getRooms();
		int getID(); 
	}; 
#endif
