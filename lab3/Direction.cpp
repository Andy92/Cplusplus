#include "Direction.hpp"
using namespace std;
using namespace lab3;


		Direction::Direction(string name) {
			this->name = name;
		}
		/* r = from room
		 * name = direction name/id
		 * tor = to room
		 */
		Direction::Direction(Room *r, string name, Room *tor) {
			this->tor = tor;
			this->r = r;
			this->name = name;
			addDirs();
		}

		void Direction::addDirs() {
			vector<Direction> dirs = this->r->getDirections();
			dirs.push_back(*this);
			//cout << " DirName: " << dirs[0].getName() << endl;
			this->r->setDirections(dirs);
		}

		//TODO: Delete this? Unessesary maybe.
		void Direction::changeRoom(Room *r){
			this->r = r;
		}

		string Direction::getName() {
			return this->name;
		}