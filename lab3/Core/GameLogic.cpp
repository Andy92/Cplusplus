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

	case 44 : std::cout << "FightingMode" << std::endl;
		this->fightingMode();
		break;
	case 55 : 
		std::cout << this->ch->getQuest()->getMainObjective() << std::endl;
		break;
	case 66 : std::cout << "===============item list====================" << std::endl;
		this->backpackMode();
		break;
	case 77 : std::cout << "===============item list====================" << std::endl;
		this->inventoryMode();
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

std::cout << raceInt << std::endl;
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
std::cout << profInt << std::endl;
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

void GameLogic::combat1v1(Character* first, Creature* second){

	std::string winner;
	if(second->hp == 0) {
		std::cout << "This monster is dead, you cannot fight a dead monster. Type LOOT to try to loot it." << std::endl;
	} else {
		while(true) {
			first->hit(second->str+second->wepdmg);
			if(first->hp <= 0) {
				winner = second->toString();
				break;
			}
			second->hit(first->str+first->wepdmg);
			if(second->hp <= 0) {
				winner = first->toString();
				first->drop(second);
				break;
			}
		}
		std::cout << "And the winner is: " <<  winner << std::endl;
	}
}


void GameLogic::backpackMode() {
	this->ch->getChar()->displayitems();
	int equipitem = -1;
	std::cout << "EQUIP> ";
	equipitem = takeInt();
	if(equipitem < 0 || equipitem >= this->ch->getChar()->Items.size()) { // bokstäver går förbi checken
		std::cout << "ERROR: choice: " << equipitem << " is not available." << std::endl;
	} else {
		std::cout << "registered choice: " << equipitem << std::endl;
		this->ch->getChar()->equip(this->ch->getChar()->Items.at(equipitem));
		this->ch->getChar()->Items.erase(this->ch->getChar()->Items.begin()+equipitem);
	}
}

void GameLogic::inventoryMode() {
	this->ch->getChar()->displayEquippedItems();
	int unequipitem = -1;
	std::cout << "UNEQUIP> ";
	unequipitem = takeInt();
	if(unequipitem < 1 || unequipitem > 4) { // bokstäver går förbi checken
		std::cout << "ERROR: choice: " << unequipitem << " is not available." << std::endl;
	} else {
		std::cout << "registered choice: " << unequipitem << std::endl;
		switch(unequipitem) {
			case 1:
				this->ch->getChar()->Items.push_back(this->ch->getChar()->unEquipWep());
				break;
			case 2:
				this->ch->getChar()->Items.push_back(this->ch->getChar()->unEquipHelm());
				break;
			case 3:
				this->ch->getChar()->Items.push_back(this->ch->getChar()->unEquipChest());
				break;
			case 4:
				this->ch->getChar()->Items.push_back(this->ch->getChar()->unEquipLegs());
				break;
		}
	}
}

int GameLogic::takeInt() {
	std::string ss;
	int ret = -1;
	std::getline(std::cin, ss); 
	ret = atoi(ss.c_str());
	return ret; 
}
void GameLogic::fightingMode() {
	std::cout << "choose between available monsters to fight: " << std::endl;
	std::vector<Creature*> cl = this->ch->getRoom()->getCreatureList();
	for(unsigned int i=0;i<cl.size();++i){
		std::cout << cl.at(i)->toString() << " to fight this monster press: " << (i) << std::endl;
	}
	int fightmob = -1;
	std::cout << "FIGHTING> ";
	fightmob = takeInt();
	if(fightmob < 0 || fightmob >= cl.size()) { // bokstäver går förbi checken
		std::cout << "ERROR: choice: " << fightmob << " is not available." << std::endl;
	} else {
		std::cout << "registered choice: " << fightmob << std::endl;
		combat1v1(this->ch->getChar(), cl.at(fightmob));
	}
}