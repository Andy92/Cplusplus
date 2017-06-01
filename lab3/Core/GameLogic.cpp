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

// Move character from current room to given room.
bool GameLogic::changeDir(std::string newDir) {
	Room* oldRoom = ROOM;
	std::vector<Direction> dirs = oldRoom->getDirections();
	for(int i =0; i < dirs.size() ;++i) {
		if(dirs.at(i).getName().compare(newDir) == 0) {
			Room* newRoom = dirs.at(i).getToRoom();
			return this->ch->moveChar(newRoom);
		}
	}
	return false;
}

void GameLogic::getDirections() {
	std::vector<Direction> dirs2 = ROOM->getDirections();
	for(int k=0;k<dirs2.size();++k) {
		std::cout << dirs2.at(k).getName() << std::endl;
	}
}

void GameLogic::ExecCmd(int parsedInt) {
	switch(parsedInt) {
	case 0 : std::cout << "go west" << std::endl;
		this->changeDir("West"); // go east
		break; // go west
	case 1 : std::cout << "go east" << std::endl;
		this->castleTax();
		break;
	case 2 : std::cout << "go north" << std::endl;
		this->changeDir("North"); // go east
		break;
	case 3 : std::cout << "go south" << std::endl;
		this->changeDir("South"); // go east
		break;
	case 666 : std::cout << "Your character: " << CHARAC->toString() << std::endl;
		std::cout << "You are at roomID: " << ROOM->getID() << " at environment: " << ROOM->getEnvDesc() << std::endl;
		break;
	case 22 : std::cout << "Available commands:" << std::endl;
			std::cout << "GO, STATS, HELP, EXIT, FIGHT, QUEST, ITEMS, INV, SHOP, TALK" << std::endl;
		break;
	case 33 : std::cout << "Exiting the program..." << std::endl;
		exit(0);
		break;
	case 44 : std::cout << "FightingMode" << std::endl;
		this->fightingMode();
		break;
	case 55 : 
		this->outputQuestObj();
		break;
	case 66 : std::cout << "===============item list====================" << std::endl;
		this->backpackMode();
		break;
	case 77 : std::cout << "===============equipped list====================" << std::endl;
		this->inventoryMode();
		break;
	case 88 : std::cout << "=================shopkeeper list=================" << std::endl;
		this->shopkeeperMode();
		break;
	case 4 : std::cout << "=================directions=================" << std::endl;
		this->getDirections();
		break;
	case 99 : std::cout << "=================talking=================" << std::endl;
		this->talking();
		break;
	default : std::cout << "default" << std::endl;
		break;
}
}

void GameLogic::castleTax() {



	// outside castle entrance
	if(ROOM->getID() == 2003) {
			if(this->ch->getTax()) {
				std::cout << "Guard: Have you payed the tax for today? Would you like to?" << std::endl;
				std::string str;
				std::cout << std::endl << "TALK> ";
				std::getline (std::cin,str);
				if(str == "yes") {
					int cc = CHARAC->getcoins();
					if(cc >= 5000) {
						CHARAC->setcoins(cc - 5000);
						std::cout << "Guard: Thank you, i will deliver this 5000 coins to the kings treasure." << std::endl;
						this->ch->payTax();
					} else {
						std::cout << "You have not payed taxes for years, it has accumulated into 5000 coins." << std::endl;
					}
				} else {
					std::cout << "Guard: Well unless you answer me yes and accept to pay taxes i can't let you in." << std::endl;
				}
			}else {
				std::cout << "Guard: Welcome to the king's castle sir." << std::endl;
				this->changeDir("East"); // go east
			}
			// outside dragonlair
		} else if(ROOM->getID() == 3003) {
			if(this->ch->getQuest()->checkQuest(2)
			&& this->ch->getQuest()->checkQuest(3)) {
				this->changeDir("East"); // go east
			} else {
				std::cout << "You are trying to enter the dragon lair, but you shiver in fear and do not dare to enter." << std::endl;
				std::cout << "Maybe if you complete all the other quests and get stronger you might be more confident." << std::endl;
			}


		} else {
			this->changeDir("East"); // go east
		}



}
void GameLogic::talking() {
	if(ROOM->getID() == 5004) {
		this->ch->getQuest()->setQuest(2);
	}
	else if(ROOM->getID() == 6008) {
		this->ch->getQuest()->setQuest(3);
	}
}

void GameLogic::outputQuestObj() {
	Quest* quest = this->ch->getQuest();
	std::cout << quest->getMainObjective() << std::endl;
	if(quest->checkQuest(2)){
		std::cout << quest->getSecondaryObjective() << std::endl;
	}
	if(quest->checkQuest(3)){
		std::cout << quest->getThirdObjective() << std::endl;
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

std::cerr << raceInt << std::endl;
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
std::cerr << profInt << std::endl;
if(profInt == -1) {
	std::cout << "Non existant profession, try again!" << std::endl;
}
}
Character *retCharac = 0;
switch(raceInt) {
	case 0 : std::cout << "you are a human ";
	switch(profInt) {
		case 0 : std::cout << "warrior" << std::endl;
		retCharac = new Character(new Human(), new Warrior());
			break; // go west
			case 1 : std::cout << "wizard" << std::endl;
			retCharac = new Character(new Human(), new Wizard());
			break;
			default : std::cerr << std::endl << "ERROR: Bad profession, exception!" <<  std::endl;
			exit(-1);
		}
	break; // go west
	case 1 : std::cout << "you are an orc ";
	switch(profInt) {
		case 0 : std::cout << "warrior" << std::endl;
		retCharac = new Character(new Orc(), new Warrior());
			break; // go west
			case 1 : std::cout << "wizard" << std::endl;
			retCharac = new Character(new Orc(), new Wizard());
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
	if(second->gethp() == 0) {
		std::cout << "This monster is dead, you cannot fight a dead monster. " << std::endl;
	} else {
		while(true) {
			first->hit(second->getstr());
			if(first->gethp() <= 0) {
			std::cout << "And the winner is: Creature" << std::endl;
				break;
			}
			second->hit(first->getstr()+first->getwep()->getdmg());
			if(second->gethp() <= 0) {
			std::cout << "And the winner is: You" << std::endl;
				first->drop(second);
				break;
			}
		}
	}
}


void GameLogic::backpackMode() {
	CHARAC->displayitems();
	std::vector<Item*> bitems = CHARAC->getItems();
	int equipitem = -1;
	std::cout << "ITEMS> ";
	equipitem = takeInt();
	if(equipitem < 0 || equipitem >= bitems.size()) { // bokstäver går förbi checken
		std::cout << "ERROR: choice: " << equipitem << " is not available." << std::endl;
	} else {
		std::cout << "registered choice: " << equipitem << std::endl;
		CHARAC->equip(bitems.at(equipitem));
		bitems.erase(bitems.begin()+equipitem);
	}
}

void GameLogic::inventoryMode() {
	CHARAC->displayEquippedItems();
	int unequipitem = -1;
	std::vector<Item*> iitems = CHARAC->getItems();
	std::cout << "UNEQUIP> ";
	unequipitem = takeInt();
	if(unequipitem < 1 || unequipitem > 4) { // bokstäver går förbi checken
		std::cout << "ERROR: choice: " << unequipitem << " is not available." << std::endl;
	} else {
		std::cout << "registered choice: " << unequipitem << std::endl;
		switch(unequipitem) {
			case 1:
				iitems.push_back(CHARAC->unEquipWep());
				break;
			case 2:
				iitems.push_back(CHARAC->unEquipHelm());
				break;
			case 3:
				iitems.push_back(CHARAC->unEquipChest());
				break;
			case 4:
				iitems.push_back(CHARAC->unEquipLegs());
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
	std::vector<Creature*> cl = ROOM->getCreatureList();
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
		combat1v1(CHARAC, cl.at(fightmob));
	}
}
void GameLogic::shopkeeperMode() {
	std::cout << "you have: " << CHARAC->getcoins() << " coins, choose between available items to purchase or go into sell mode: " << std::endl;
	ROOM->getShopkeeper()->displayInventory();
	int shopitem = -1;
	std::vector<Item*> sitems = CHARAC->getItems();
	std::cout << "SHOP> ";
	shopitem = takeInt();

	if(shopitem == ROOM->getShopkeeper()->getinv().size()) {
		this->sellMode();
	}
	else if((shopitem < 0 || shopitem >= ROOM->getShopkeeper()->getinv().size()) || CHARAC->getcoins() < ROOM->getShopkeeper()->getinv().at(shopitem)->getvalue()) {
		std::cout << "ERROR: choice: " << shopitem << " is not available." << std::endl;
	}
	else {
		sitems.push_back(ROOM->getShopkeeper()->getinv().at(shopitem));
		int currcoins = CHARAC->getcoins();
		currcoins -= ROOM->getShopkeeper()->getinv().at(shopitem)->getvalue();
		CHARAC->setcoins(currcoins);
	}
}
void GameLogic::sellMode() {
	std::cout << "Sell mode, you have: " << CHARAC->getcoins() << "coins, choose between available items to sell from your getinv()" << std::endl;
	std::vector<Item*> Itemvec = CHARAC->getItems();
	for(int i =0; i < Itemvec.size() ;++i) {
			std::cout << "press: " << i << " to sell item: " << Itemvec.at(i)->desc() << std::endl;
		}
	int sellitem = -1;
	std::cout << "SELL> ";
	sellitem = takeInt();

	if(sellitem < 0 || sellitem >= Itemvec.size()) {
		std::cout << "ERROR: choice: " << sellitem << " is not available." << std::endl;
	}
	else {

		CHARAC->setcoins(CHARAC->getcoins() + Itemvec.at(sellitem)->getvalue());
		Itemvec.erase(Itemvec.begin() + sellitem);
		CHARAC->setItems(Itemvec);
	}
}