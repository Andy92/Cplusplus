
#include "Main.hpp"
void Main::combat1v1(Character *first, Creature *second){
	std::string winner;
	while(true) {
		first->hit(second->str);
		if(first->hp <= 0) {
			winner = second->r->id;
			break;
		}
		second->hit(first->str);
		if(second->hp <= 0) {
			winner = first->r->id;
			break;
		}
	}
	cout << winner << endl;
		}

		void Main::Init() {
	
	

	//Creature List
	std::vector<Creature*> creatures; 
	std::vector<Creature*> creatures2;
	std::vector<Creature*> creatures3;
	std::vector<Creature*> creatures4;
	std::vector<Creature*> creatures5;    




	
	// Environments
	Environment *e1 = new Environment("TavernDesc");
	Environment *e2 = new Environment("BeachDesc");

	//Rooms
	std::vector<Room> ruums;
	Room *rum = new Room(e1, creatures);
	Room *rum2 = new Room(e1, creatures2);
	Room *rum3 = new Room(e1, creatures3);
	Room *rum4 = new Room(e1, creatures4);
	Room *rum5 = new Room(e2, creatures5);

	Character *charr = new Character(new Human("Human"), new Warrior("Warrior"));
	Creature *creat = new Creature(new Orc("Orc"));

	creatures.push_back(creat);
	creatures.push_back(charr);
	
	
	cout << charr->toString() << endl;
  	cout << creat->toString() << endl;

  	
  	combat1v1(charr, creat);
  	cout << charr->toString() << endl;
  	cout << creat->toString() << endl;
	
	//Directions
	//rum
	Direction *ex = new Direction(rum, "East", rum2);
	Direction *ex2 = new Direction(rum, "South", rum3);

	//rum2
	Direction *ex3 = new Direction(rum2, "West", rum);
	Direction *ex4 = new Direction(rum2, "South", rum4);

	//rum3
	Direction *ex5 = new Direction(rum3, "North", rum);
	Direction *ex6 = new Direction(rum3, "East", rum4);
	//rum4
	Direction *ex7 = new Direction(rum4, "West", rum3);
	Direction *ex8 = new Direction(rum4, "North", rum2);
	Direction *ex9 = new Direction(rum4, "East", rum5);

	//rum5
	Direction *ex10 = new Direction(rum5, "West", rum4);


	
	cout << "Description:" << e1->getDesc() << endl;
	std::vector<Room> rooms = e1->getRooms();
	cout << "Nr of Rooms: " << rooms.size() << endl;
	for(int i=0;i<rooms.size();++i) {
		std::vector<Direction> dirs = rooms[i].getDirections();
		cout << endl;
		cout << "EnvDesc: " << rooms[i].getEnvDesc() << " Room: " << rooms[i].getID() << " Directions: " << dirs.size();
		for (int v = 0; v < dirs.size(); ++v) {
			cout << " " << dirs[v].getName();
		}
	}

	cout << endl;
		
		}

		void Main::Game() {
			while(true) {
				std::string s;
				std::cin >> s;
				Parser se;
				se.Parse(s);
			}
		}




int main() {
			cout << "\033[33mStarting game\033[37m" << endl;
			Main gn;
			gn.Init();
			gn.Game();
			cout << "\033[33mGame ended\033[37m" << endl;
		}
