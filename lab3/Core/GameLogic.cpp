#include "GameLogic.hpp"
std::vector<std::string> GameLogic::Races = {
		"human",
		"orc"
	};

	std::vector<std::string> GameLogic::Professions{
		"warrior",
		"wizard"
	};



GameLogic::GameLogic(Checker* ch) {
	this->ch = ch;
}

bool GameLogic::changeDir(std::string newDir) {
	Room* oldRoom = this->ch->getRoom();
	std::vector<Direction> dirs = oldRoom->getDirections();
	for(int i =0; i < dirs.size() ;++i) {
		if(dirs.at(i).getName().compare(newDir) == 0) {
			Room* newRoom = dirs.at(i).getToRoom();
			return this->ch->moveChar(newRoom);
		}
	}
	return false;
}

void GameLogic::ExecCmd(int parsedInt) {
	switch(parsedInt) {
		case 0 : std::cout << "go west" << std::endl;
			this->changeDir("West"); // go east
			break; // go west
		case 1 : std::cout << "go east" << std::endl;
			this->changeDir("East"); // go east
			break;
		case 2 : std::cout << "go north" << std::endl;
			this->changeDir("North"); // go east
			break;
		case 3 : std::cout << "go south" << std::endl;
			this->changeDir("South"); // go east
			break;
		case 666 : std::cout << "Your character: " << this->ch->getChar()->toString() << std::endl;
			std::cout << "You are at roomID: " << this->ch->getRoom()->getID() << " at environment: " << this->ch->getRoom()->getEnvDesc() << std::endl;
			break;
		case 33 : std::cout << "Exiting the program..." << std::endl;
			exit(0);
			break;
		default : std::cout << "default" << std::endl;
			break;
	}
}
// 
Character* GameLogic::charCreation() {
	
	std::string s;
	int raceInt = -1;
	int profInt = -1;

	while(raceInt == -1) {
		std::cout << "Available Races are: Human, Orc" << std::endl;
		std::cout << "Choose your Race: ";
		std::getline (std::cin,s);

		transform(s.begin(), s.end(), s.begin(),::tolower);
		for(int i=0; i<Races.size(); ++i) { //Race iteration
			if(s.find(Races.at(i)) == 0) {
				raceInt = i;
			}
		}

		std::cout << raceInt << endl;
		if(raceInt == -1) {
			std::cout << "Non existant race, try again!" << std::endl;
		}
	}

	while(profInt == -1) {
		std::cout << "Available professions are: Warrior, Wizard" << std::endl;
		std::cout << "Choose your Profession: ";
		std::getline (std::cin,s);

		transform(s.begin(), s.end(), s.begin(),::tolower);
		
		for(int i=0; i<Professions.size(); ++i) { //Race iteration
			if(s.find(Professions.at(i)) == 0) {
				profInt = i;
			}
		}
		std::cout << profInt << endl;
		if(profInt == -1) {
			std::cout << "Non existant profession, try again!" << std::endl;
		}
	}
	Character *retCharac = 0;
	switch(raceInt) {
		case 0 : std::cout << "you are a human ";
			switch(profInt) {
				case 0 : std::cout << "warrior" << std::endl;
				retCharac = new Character(new Human("Human"), new Warrior("Warrior"));
					break; // go west
				case 1 : std::cout << "wizard" << std::endl;
				retCharac = new Character(new Human("Human"), new Wizard("Wizard"));
					break;
				default : std::cerr << std::endl << "ERROR: Bad profession, exception!" <<  std::endl;
					exit(-1);
			}
			break; // go west
		case 1 : std::cout << "you are an orc ";
			switch(profInt) {
				case 0 : std::cout << "warrior" << std::endl;
				retCharac = new Character(new Orc("Orc"), new Warrior("Warrior"));
					break; // go west
				case 1 : std::cout << "wizard" << std::endl;
				retCharac = new Character(new Orc("Orc"), new Wizard("Wizard"));
					break;
				default : std::cerr << std::endl << "ERROR: Bad profession, try again!" <<  std::endl;
					exit(-1);
			}
			break;
		default : std::cerr << std::endl << "ERROR: Bad race, exception!" <<  std::endl;
			exit(-1);
		}
	return retCharac;
}