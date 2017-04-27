class Environment {
	public:

		String description = "";
		Room[] rooms;
		
		Environment(String descr, Room[] rooms) {
			this->rooms = rooms;
			this->description = descr;
		}

};

class Room {
	exit[] exits;
	Creature[] creatures;
	Environment *e;

	Room(Environment *e, exit[] exits, Creature[] creatures) {
		this->e = e;
		this->exits = exits;
		this->creatures = creatures;
	}
};

class Tavern : public Environment {
	public:
		Vendor v = 0;
		questNPC q = 0;

};

class Beach : public Environment {
	public:
		Beach(String descr, room[] rooms) : Environment(descr, rooms) {

		}
};