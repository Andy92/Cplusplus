#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#ifndef DIRECTION_HPP
#define DIRECTION_HPP
	class Room;

	class Direction {
	private:
		Room *r;
		Room *tor;
		std::string name = "";
		
		public:
			Direction(std::string name);
			Direction(Room *r, std::string name, Room *tor);
			void addDirs();

			void changeRoom(Room *r);
			std::string getName();
			Room* getToRoom();
	};

#endif
