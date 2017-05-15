using namespace std;

#ifndef DIRECTION_HPP
#define DIRECTION_HPP


namespace lab3 {
	class Room;
	class Direction {
	private:
		Room *r;
		Room *tor;
		string name = "";
		
		public:
			Direction(string name);
			Direction(Room *r, string name, Room *tor);
			void addDirs();

			void changeRoom(Room *r);
			string getName();
	};
}

#endif