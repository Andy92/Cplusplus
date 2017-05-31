#include "Main.hpp"


void Main::Init() {
	
	

	//Creature List
	std::vector<Creature*> creatures; 
	std::vector<Creature*> creatures2;
	std::vector<Creature*> creatures3;
	std::vector<Creature*> creatures4;
	std::vector<Creature*> creatures5;    




	
	// Environments
	Environment *e1 = new Environment("TavernDesc", 1);
	Environment *e2 = new Environment("BeachDesc", 2);

	//Rooms
	Creature *creat = new Creature(new Orc("Orc"), 3);


	creatures.push_back(creat);
	Room *rum = new Room(e1, creatures);
	Room *rum2 = new Room(e1, creatures2);
	Room *rum3 = new Room(e1, creatures3);
	Room *rum4 = new Room(e1, creatures4);
	Room *rum5 = new Room(e2, creatures5);
	



	
	//Character *charr = new Character(new Human("Human"), new Warrior("Warrior"));
	
	
	//cout << charr->toString() << endl;
  	std::cout << creat->toString() << std::endl;

  	
  	//combat1v1(charr, creat);
  	//std::cout << charr->toString() << std::endl;
  	std::cout << creat->toString() << std::endl;
	
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
	
	this->roomVec.push_back(rum);
	this->roomVec.push_back(rum2);
	this->roomVec.push_back(rum3);
	this->roomVec.push_back(rum4);
	this->roomVec.push_back(rum5);

	std::cout << "Description:" << e1->getDesc() << std::endl;
	std::vector<Room> rooms = e1->getRooms();
	std::cout << "Nr of Rooms: " << rooms.size() << std::endl;
	for(int i=0;i<rooms.size();++i) {
		std::vector<Direction> dirs = rooms[i].getDirections();
		std::cout << std::endl;
		std::cout << "EnvDesc: " << rooms[i].getEnvDesc() << " Room: " << rooms[i].getID() << " Directions: " << dirs.size();
		for (int v = 0; v < dirs.size(); ++v) {
			std::cout << " " << dirs[v].getName();
		}
	}

	std::cout << std::endl;
		
}

		void Main::Game() {
			Character *charr = gl->charCreation();

			this->roomVec.at(0)->setChar(charr);
			this->ch = new Checker(charr, this->roomVec.at(0), this->roomVec);
			this->gl = new GameLogic(this->ch);

			while(true) {
				std::string s;

				std::cout << std::endl << "RPG> ";
				std::getline (std::cin,s);
				std::cout << std::endl;
				Parser se;
				int par = se.Parse(s);
				gl->ExecCmd(par);
			}
		}




int main() {
			std::cout << "\033[33mStarting game\033[37m" << std::endl;
			Main gn;
			gn.Init();
			gn.Game();
			std::cout << "\033[33mGame ended\033[37m" << std::endl;
		}
