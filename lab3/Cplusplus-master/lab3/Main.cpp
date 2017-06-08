#include "Main.hpp"
std::vector<Room*> Main::roomVec;

void Main::Init() {
	
	//shopkeeperlist
	std::vector<Item*> inventory;
	inventory.push_back(new Weapon(250,std::string("noobwep"), 100));
	inventory.push_back(new Legs(15,std::string("nooblegs"), 100));
	inventory.push_back(new Chest(20,std::string("noobchest"), 100));
	inventory.push_back(new Helm(25,std::string("noobhelm"), 100));
	Shopkeeper *sk = new Shopkeeper(inventory);
	
	//Creature List
	std::vector<Creature*> creatures; 
	std::vector<Creature*> creatures2;
	std::vector<Creature*> creatures3;
	std::vector<Creature*> creatures4;
	std::vector<Creature*> creatures5;
	std::vector<Creature*> creatures7;
	//std::vector<Creature*> creatures8;
	std::vector<Creature*> creaNull;
	
	// Environments
	Environment *e1 = new Environment("Tavern", 1);
	Environment *e2 = new Environment("Road", 2);
	Environment *e3 = new Environment("forest", 3);
	Environment *e4 = new Environment("Dragon lair", 4);
	Environment *e5 = new Environment("Town", 5);
	Environment *e6 = new Environment("Castle", 6);

	//Creatures
	creatures.push_back(new Creature(new Orc(), 1));
	creatures2.push_back(new Creature(new Bandit(), 1));
	creatures2.push_back(new Creature(new Bandit(), 1));
	creatures2.push_back(new Creature(new Bandit(), 1));

	creatures3.push_back(new Creature(new Knight(), 2));
	creatures3.push_back(new Creature(new Knight(), 2));

	creatures4.push_back(new Creature(new Knight(), 2));
	creatures4.push_back(new Creature(new Knight(), 2));
	creatures4.push_back(new Creature(new Knight(), 3));
	creatures4.push_back(new Creature(new Knight(), 2));
	creatures4.push_back(new Creature(new Knight(), 2));

	creatures5.push_back(new Creature(new Knight(), 4));

	creatures7.push_back(new Creature(new Dragon(), 5));

	
	// Tavern
	Room *rum = new Room(e1, creatures, "You are at the tavern hall, you see the exit to the west.");
	Room *rum2 = new Room(e1, creaNull, "This is a empty room.");
	Room *rum3 = new Room(e1, creaNull, "This room have a beatiful view to the mountains.");
	Room *rum4 = new Room(e1, creaNull, "This is another empty room.");


	// Road
	Room *rrum = new Room(e2, creatures2, "You are in a dangerous road, there are usually bandits here that are waiting to rob someone.");
	Room *rrum2 = new Room(e2, creaNull, "You are at the main road. You see a sign in the south that says \"Town\"");
	Room *rrum3 = new Room(e2, creaNull, "You are on a road that seems to lead to a big castle that you see far to the east.");
	Room *rrum4 = new Room(e2, creaNull, "You are very close to the castle entrance. You see a guard standing at the entrance.");

	// Forest
	ForestRoom *frum = new ForestRoom(e3, creatures4, "You see a big hut and a camp fire, seems bandits used to live here.");
	ForestRoom *frum2 = new ForestRoom(e3, creatures5, "This forest is beautiful and have a big mountain to the far far east.");
	ForestRoom *frum3 = new ForestRoom(e3, creatures3, "You keep going through the forest.");
	ForestRoom *frum4 = new ForestRoom(e3, creaNull, "This forest have a lot of mountains, you are sourrounded by mountains in all directions, there is a big cave hole on the mountain to the east.");

	// Dragon Lair
	Room *drum = new Room(e4, creatures7, "You are in a dragon lair, you see and face a big big dragon, would you want to fight it, it seems powerful?");

	// Town
	TownRoom *trum = new TownRoom(e5, creaNull, "You are inside a house.");
	TownRoom *trum2 = new TownRoom(e5, creaNull, "From this place you see a burned house to the south and a shop to the west-south.");
	TownRoom *trum3 = new TownRoom(e5, creaNull, "You can see a shop to the south.");
	TownRoom *trum4 = new TownRoom(e5, creaNull, "There is a road to the east that seems pretty long.");
	TownRoom *trum5 = new TownRoom(e5, creaNull, "You are at the shop, you see a man standing here very worried about some things, maybe talk to him?");
	TownRoom *trum6 = new TownRoom(e5, creaNull, "This house looks burned, the people who used to live there are crying.");
	

	// Castle
	Room *crum = new Room(e6, creaNull, "You've entered a room. This bedroom is full of wine and food.");
	Room *crum2 = new Room(e6, creaNull, "You've entered a room, this room seems to be pretty.");
	Room *crum3 = new Room(e6, creaNull, "You have accidently entered the treasure room, if you get caught being in here you are screwed.");
	Room *crum4 = new Room(e6, creaNull, "You are at the hall of the castle near the exit door.");
	Room *crum5 = new Room(e6, creaNull, "This hall is very long you can keep going to the east, there are doors to the south and north aswell.");
	Room *crum6 = new Room(e6, creaNull, "You have arrived to the end of the hall, you see big doors to the south.");
	Room *crum7 = new Room(e6, creaNull, "This is the big balcony of the castle, you can see the whole town from here.");
	Room *crum8 = new Room(e6, creaNull, "This room is a bedroom, the king and queen probably sleeps here, but none of them are here.");
	Room *crum9 = new Room(e6, creaNull, "You find yourself in the kings hall, there is a golden throne, and the king is sitting in it. Maybe go talk to him");

	
	trum5->setShopkeeper(sk);
	
	//Directions
	// ### Tavern ###
	//rum
	new Direction(rum, E, rum2);
	new Direction(rum, S, rum3);
	new Direction(rum, W, rrum2);
	//rum2
	new Direction(rum2, W, rum);
	new Direction(rum2, S, rum4);
	//rum3
	new Direction(rum3, N, rum);
	new Direction(rum3, E, rum4);
	//rum4
	new Direction(rum4, W, rum3);
	new Direction(rum4, N, rum2);

	// ##### END OF TAVERN ####

	// ### Road ###

	new Direction(rrum, N, frum2);
	new Direction(rrum, S, rrum2);
	
	new Direction(rrum2, E, rum);
	new Direction(rrum2, N, rrum);
	new Direction(rrum2, S, trum2);

	new Direction(rrum3, W, trum4);
	new Direction(rrum3, E, rrum4);

	new Direction(rrum4, W, rrum3);
	new Direction(rrum4, E, crum4);


	// ##### END OF ROAD ####

	// ### FOREST ###

	new Direction(frum, E, frum2);
	
	new Direction(frum2, E, frum3);
	new Direction(frum2, W, frum);
	new Direction(frum2, S, rrum);

	new Direction(frum3, E, frum4);
	new Direction(frum3, W, frum2);

	new Direction(frum4, E, drum);
	new Direction(frum4, W, frum3);

// ##### END OF FOREST ####

	// ### Dragon lair ###

	new Direction(drum, W, frum4);

	// ##### END OF DRAGONLAIR ####
	// ### Town ###

	new Direction(trum, S, trum3);
	
	new Direction(trum2, N, rrum2);
	new Direction(trum2, S, trum4);

	new Direction(trum3, E, trum4);
	new Direction(trum3, N, trum);
	new Direction(trum3, S, trum5);

	new Direction(trum4, E, rrum3);
	new Direction(trum4, W, trum3);
	new Direction(trum4, N, trum2);
	new Direction(trum4, S, trum6);

	new Direction(trum5, N, trum3);

	new Direction(trum6, N, trum4);

	// ##### END OF TOWN ####
	// ### CASTLE ###
	new Direction(crum, S, crum4);

	new Direction(crum2, S, crum5);

	new Direction(crum3, S, crum6);

	new Direction(crum4, E, crum5);
	new Direction(crum4, W, rrum4);
	new Direction(crum4, N, crum);
	new Direction(crum4, S, crum7);

	new Direction(crum5, E, crum6);
	new Direction(crum5, W, crum4);
	new Direction(crum5, N, crum8);
	new Direction(crum5, S, crum2);

	new Direction(crum6, W, crum5);
	new Direction(crum6, N, crum3);
	new Direction(crum6, S, crum9);

	new Direction(crum7, E, crum8);
	new Direction(crum7, N, crum4);

	new Direction(crum8, W, crum7);
	new Direction(crum8, N, crum5);

	new Direction(crum9, N, crum6);

	// ##### END OF CASTLE ####


	// All rooms in a list.
	this->roomVec.push_back(rum);
	this->roomVec.push_back(rum2);
	this->roomVec.push_back(rum3);
	this->roomVec.push_back(rum4);

	this->roomVec.push_back(rrum);
	this->roomVec.push_back(rrum2);
	this->roomVec.push_back(rrum3);
	this->roomVec.push_back(rrum4);

	this->roomVec.push_back(frum);
	this->roomVec.push_back(frum2);
	this->roomVec.push_back(frum3);
	this->roomVec.push_back(frum4);

	this->roomVec.push_back(drum);

	this->roomVec.push_back(trum);
	this->roomVec.push_back(trum2);
	this->roomVec.push_back(trum3);
	this->roomVec.push_back(trum4);
	this->roomVec.push_back(trum5);
	this->roomVec.push_back(trum6);

	this->roomVec.push_back(crum);
	this->roomVec.push_back(crum2);
	this->roomVec.push_back(crum3);
	this->roomVec.push_back(crum4);
	this->roomVec.push_back(crum5);
	this->roomVec.push_back(crum6);
	this->roomVec.push_back(crum7);
	this->roomVec.push_back(crum8);
	this->roomVec.push_back(crum9);

	// END OF ROOMLIST


	std::cerr << std::endl;

}

		void Main::Game() {
			Character *charr = gl->charCreation(); //Initialize char Creation process.

			this->ch = new Checker(charr, this->roomVec.at(0), this->roomVec); // Put char, starting room and vector of all rooms.
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
