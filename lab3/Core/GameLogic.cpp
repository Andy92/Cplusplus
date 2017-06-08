#include "GameLogic.hpp"
std::vector<std::string> GameLogic::Races {
	"human",
	"orc"
};

std::vector<std::string> GameLogic::Professions {
	"warrior",
	"wizard"
};

<<<<<<< HEAD
=======
GameLogic::~GameLogic() {
	delete this->ch;
}
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965

GameLogic::GameLogic(Checker* ch) {
	this->ch = ch;
}

// Move character from current room to given room.
bool GameLogic::changeDir(std::string newDir) {
	Room* oldRoom = ROOM;
	std::vector<Direction*> dirs = oldRoom->getDirections();
	for(int i =0; i < dirs.size() ;++i) {
		if(dirs.at(i)->getName().compare(newDir) == 0) {
			Room* newRoom = dirs.at(i)->getToRoom();
<<<<<<< HEAD
			return this->ch->moveChar(newRoom);
=======
			this->ch->moveChar(newRoom);
			return true;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		}
	}
	return false;
}

void GameLogic::getDirections() {
	std::vector<Direction*> dirs2 = ROOM->getDirections();
	for(int k=0;k<dirs2.size();++k) {
		std::cout << dirs2.at(k)->getName() << std::endl;
	}
}

void GameLogic::ExecCmd(int parsedInt) {
	switch(parsedInt) {
<<<<<<< HEAD
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
=======
	case 0 : std::cerr << "go west" << std::endl;
		this->changeDir("West"); // go east
		break; // go west
	case 1 : std::cerr << "go east" << std::endl;
		this->castleTax();
		break;
	case 2 : std::cerr << "go north" << std::endl;
		this->changeDir("North"); // go east
		break;
	case 3 : std::cerr << "go south" << std::endl;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		this->changeDir("South"); // go east
		break;
	case 666 : std::cout << "Your character: " << CHARAC->toString() << std::endl;
		std::cout << "You are at roomID: " << ROOM->getID() << " at environment: " << ROOM->getEnvDesc() << std::endl;
		break;
	case 22 : std::cout << "Available commands:" << std::endl;
<<<<<<< HEAD
			std::cout << "GO, STATS, HELP, EXIT, FIGHT, QUEST, ITEMS, INV, SHOP, TALK" << std::endl;
		break;
	case 33 : std::cout << "Exiting the program..." << std::endl;
		delete this->ch;
=======
			std::cout << "GO, STATS, HELP, EXIT, FIGHT, QUEST, ITEMS, INV, SHOP, TALK, SPEC, DESC, LOOK" << std::endl;
		break;
	case 33 : std::cout << "Exiting the program..." << std::endl;
		delete this;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
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
	case 88 : if(ROOM->getShopkeeper() == NULL) {
			std::cout << "there is no available shopkeeper here";
			break;
		}
		std::cout << "=================shopkeeper list=================" << std::endl;
		this->shopkeeperMode();
		break;
<<<<<<< HEAD
	case 4 : std::cout << "=================disetShoprections=================" << std::endl;
=======
	case 4 : std::cout << "=================directions=================" << std::endl;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		this->getDirections();
		break;
	case 99 : std::cout << "=================talking=================" << std::endl;
		this->talking();
		break;
<<<<<<< HEAD
=======
	case 100: std::cout << "=================Special=================" << std::endl;
		this->Special();
		break;
	case 101: if(CHARAC->getwep() != NULL) std::cout << "weapon description: " << CHARAC->getwep()->desc() << std::endl;
		else std::cout << "equip a weapon to see its desc"; 
		break;
	case 102: std::cout << "Looking for items..." << std::endl;
		this->findGodSword();
		break;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	default : std::cout << "default" << std::endl;
		break;
}
}

<<<<<<< HEAD
=======
void GameLogic::findGodSword() {
	if(ROOM->getID() == 6002) {
		std::vector<Item*> asditems = CHARAC->getItems();
		std::cout << "you find something interesting lying around" << std::endl;
		asditems.push_back(new GodSword(10000, "You are the best", 10000000));
		CHARAC->setItems(asditems);
	}
}

void GameLogic::Special() {
	if(CHARAC->getwep() != NULL) {
		int option = CHARAC->getwep()->spec();
		switch(option) {
		case 2:	
			CHARAC->setRace(new Knight());
			this->ch->moveChar(this->ch->getQuest()->getSpecificRoom(6008));
			break;
		case 3:
			CHARAC->setRace(new Dragon());
			this->ch->moveChar(this->ch->getQuest()->getSpecificRoom(5005));
			break;
		case 4:
			std::cout << "Congratulations you have finished the game" << std::endl;
			delete this;
			exit(0);
			break;
		default: CHARAC->hit(10); 
			break;
		}
		
	}
	else std::cout << "you should equip a weapon if u want to use its special" << std::endl;
}

>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
void GameLogic::castleTax() {



	// outside castle entrance
	if(ROOM->getID() == 2003) {
			if(!this->ch->getTax()) {
				std::cout << "Guard: Have you payed the tax for today? Would you like to?" << std::endl;
				std::string str;
				std::cout << std::endl << "TALK> ";
				std::getline (std::cin,str);
				if(str == "yes") {
					int cc = CHARAC->getcoins();
					if(cc >= 2000) {
						CHARAC->setcoins(cc - 2000);
						std::cout << "Guard: Thank you, i will deliver this 2000 coins to the kings treasure." << std::endl;
						this->ch->payTax();
					} else {
						std::cout << "You have not payed taxes for years, it has accumulated into 2000 coins, you only have " << CHARAC->getcoins() << "." << std::endl;
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
		if(this->ch->getQuest()->checkSecondaryCondition()) {
			std::cout << "Shopkeeper: Alright, reports tell me the bandits are dead. Good job." << std::endl;
			std::cout << "Shopkeeper: Now to my promise, you have to visit the king in the castle and talk to him, he will tell you more." << std::endl;
		} else if(!this->ch->getQuest()->checkQuest(2)) {
			std::cout << "Shopkeeper: Have you seen the bandits at the road? They always disturb people trying to cross it. That's why i never get any customers. I wish someone could kill them." << std::endl;
			std::cout << "If you do it, i will tell you a secret." << std::endl;
		} else {
			std::cout << "Shopkeeper: Have you killed the bandits yet?" << std::endl;
		}
		this->ch->getQuest()->setQuest(2);
	} else if(ROOM->getID() == 6008) {
		if(this->ch->getQuest()->checkThirdCondition()) {
			// if third quest is completed.
			std::cout << "King: Oh wow, good job, you killed all the traitors!" << std::endl;
			if(this->ch->getQuest()->checkMainCondition()) {
				
				std::cout << "King: You have done well my friend, you saved this town!" << std::endl;
<<<<<<< HEAD
=======
				delete this;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
				exit(0);
			}
			std::cout << "King: The dragon is not dead, please kill it!" << std::endl;
		} else if(!this->ch->getQuest()->checkQuest(3)) {
			std::cout << "King: I want destroy all the traitors who fled to the forest, but have no men to do so. Please kill them for me." << std::endl;
			
		} else {
			// If it is still in progress
			std::cout << "King: Have you killed all the knights yet?" << std::endl;
		}
		this->ch->getQuest()->setQuest(3);
	} else {
		std::cout << "You are talking...\nSeems that you are not getting an answer, make sure there is someone that can hear you." << std::endl;
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
<<<<<<< HEAD
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
=======
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
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
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
			if(first->getwep() ==  NULL) {
				second->hit(first->getstr());
			}
			else{
				second->hit(first->getstr()+first->getwep()->getdmg());
			}
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
<<<<<<< HEAD
=======
	std::cout << "getitems length: " << bitems.size();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	int equipitem = -1;
	std::cout << "ITEMS> ";
	equipitem = takeInt();
	if(equipitem < 0 || equipitem >= bitems.size()) { // bokstäver går förbi checken
		std::cout << "ERROR: choice: " << equipitem << " is not available." << std::endl;
	} else {
		std::cout << "registered choice: " << equipitem << std::endl;
		bool success = CHARAC->equip(bitems.at(equipitem));
		if(success) {
			bitems.erase(bitems.begin()+equipitem);
<<<<<<< HEAD
			CHARAC->setItems(bitems);	
=======
			CHARAC->setItems(bitems);
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		}
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
<<<<<<< HEAD
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
=======
				if(CHARAC->getwep() != NULL) iitems.push_back(CHARAC->unEquipWep());
				break;
			case 2:
				if(CHARAC->gethelm() != NULL) iitems.push_back(CHARAC->unEquipHelm());
				break;
			case 3:
				if(CHARAC->getchest() != NULL) iitems.push_back(CHARAC->unEquipChest());
				break;
			case 4:
				if(CHARAC->getlegs() != NULL) iitems.push_back(CHARAC->unEquipLegs());
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
				break;
		}
		CHARAC->setItems(iitems);
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
<<<<<<< HEAD
=======
	std::vector<Item*> skitems = ROOM->getShopkeeper()->getinv();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	std::cout << "SHOP> ";
	shopitem = takeInt();

	if(shopitem == ROOM->getShopkeeper()->getinv().size()) {
		this->sellMode();
	}
	else if((shopitem < 0 || shopitem >= ROOM->getShopkeeper()->getinv().size()) || CHARAC->getcoins() < ROOM->getShopkeeper()->getinv().at(shopitem)->getvalue()) {
		std::cout << "ERROR: choice: " << shopitem << " is not available." << std::endl;
	}
	else {
<<<<<<< HEAD
		sitems.push_back(ROOM->getShopkeeper()->getinv().at(shopitem));
=======
		sitems.push_back(skitems.at(shopitem));
		skitems.erase(skitems.begin() + shopitem);
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		int currcoins = CHARAC->getcoins();
		currcoins -= ROOM->getShopkeeper()->getinv().at(shopitem)->getvalue();
		CHARAC->setcoins(currcoins);
		CHARAC->setItems(sitems);
<<<<<<< HEAD
=======
		ROOM->getShopkeeper()->setinv(skitems);
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
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