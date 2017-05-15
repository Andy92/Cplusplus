#include "Room.hpp"
using namespace std;

#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

namespace lab3 {
	class Environment {

		string description = "";
		vector<Room> rooms;
	public:
		Environment(string descr);
		void setRoom(vector<Room> rooms);
		string getDesc();
		vector<Room> getRooms();
	};
}
#endif