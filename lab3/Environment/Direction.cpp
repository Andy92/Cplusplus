#include "Direction.hpp"

		Direction::Direction(std::string name) {
			this->name = name;
		}
		/* r = from room
		 * name = direction name/id
		 * tor = to room
		 */
		Direction::Direction(Room *r, std::string name, Room *tor) {
			this->tor = tor;
			this->r = r;
			this->name = name;
			addDirs();
		}

		void Direction::addDirs() {
			std::vector<Direction> dirs = this->r->getDirections();
			dirs.push_back(*this);
			//cout << " DirName: " << dirs[0].getName() << endl;
			this->r->setDirections(dirs);
		}

		//TODO: Delete this? Unessesary maybe.
		void Direction::changeRoom(Room *r){
			this->r = r;
		}

		std::string Direction::getName() {
			return this->name;
		}

		Room* Direction::getToRoom() {
			return this->tor;
		}
