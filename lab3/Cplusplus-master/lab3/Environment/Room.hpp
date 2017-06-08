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
#define MAXROOM 1000

 	class Environment;
	class Room {
	protected:
		std::vector<Direction*> dirs;
		std::vector<Creature*> creatures;
		std::string desc = "";
		Environment *e = NULL;
		int id;
		//Creature* mainChar = 0;
		Shopkeeper* sk = NULL;
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
		//Creature* getChar();
		//void setChar(Creature* newChar);
		//bool remChar();
		std::vector<Creature*> getCreatureList();
		Shopkeeper* getShopkeeper();
		void setShopkeeper(Shopkeeper* sk);
		virtual int event() const;
	};
	class TownRoom : public Room {
	public:
		virtual int event() const;
		TownRoom(Environment *e, std::vector<Creature*> creatures, std::string description);
	};
	class ForestRoom : public Room {
	public:
		virtual int event() const;
		ForestRoom(Environment *e, std::vector<Creature*> creatures, std::string description);
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
