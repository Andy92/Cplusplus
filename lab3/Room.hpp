#include "Direction.hpp"
using namespace std;

#ifndef ROOM_HPP
#define ROOM_HPP


namespace lab3 {
	class Environment;
	class Room {
	private:
		vector<Direction> dirs;
		vector<Creature*> creatures;
		Environment *e;
		int id;
	public:
		

		Room(Environment *e, vector<Creature*> creatures);
		void setDirections(vector<Direction> dirs);
		vector<Direction> getDirections();
		void setID();
		int getID();
		bool setEnv();
		string getEnvDesc();
	};
}

#endif