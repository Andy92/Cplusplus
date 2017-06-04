#include "Quest.hpp"


/*
*  This is a quest file, where all quests will be.
*
*/



Quest::Quest(std::vector<Room*> room) {
	this->roomVec = room;
}


const std::string Quest::getObjective(const std::string qN, const std::string qT) const {
	const std::string text = YELLOW + std::string("########## ") + qN + std::string(" ################\n") + qT + YELLOW + std::string("\n######################################") + RESET;


	//YELLOW + std::string("########## MAIN QUEST ################\nDescription: " + description + YELLOW + "\nObjective: " + objective + YELLOW + "\n######################################") + RESET;

	return text;
}

const std::string Quest::getMainObjective() {

	const std::string name = "MAIN QUEST";
	const std::string description = BOLDCYAN + std::string("The dragon has been terrorizing the city, there are burned houses and destroyed streets.\n")  + RESET;
	const std::string objective = BOLDYELLOW + std::string("Kill the dragon in the dragon lair north of here.\n") + RESET;
	std::string status = "";
	if(checkMainCondition()) {
		status = BOLDGREEN + std::string("Completed\n") + RESET;
	} else {
		status = BOLDYELLOW + std::string("In progress") + RESET;
	}
	
	const std::string questText = YELLOW + std::string("Description: ") + description + YELLOW + std::string("Objective: ") + objective + YELLOW + std::string("Status: ") + status;

	return getObjective(name, questText);
}


const std::string Quest::getSecondaryObjective() {

	const std::string name = "BANDIT TROUBLE QUEST";
	const std::string description = BOLDCYAN + std::string("The bandits have brought touble to the town, they rob people who cross the road to the forrest to the north.\n")  + RESET;
	const std::string objective = BOLDYELLOW + std::string("Kill all bandits on the road.\n") + RESET;
	std::string status = "";
	if(checkSecondaryCondition()) {
		status = BOLDGREEN + std::string("Completed\n") + RESET;
	} else {
		status = BOLDYELLOW + std::string("In progress") + RESET;
	}
	
	const std::string questText = YELLOW + std::string("Description: ") + description + YELLOW + std::string("Objective: ") + objective + YELLOW + std::string("Status: ") + status;

	return getObjective(name, questText);
}

const std::string Quest::getThirdObjective() {

	const std::string name = "BANDIT PROBLEM QUEST";
	const std::string description = BOLDCYAN + std::string("The knights who abandoned their post have fled to the forest. You have to go and find their hideout in the forrest and destroy them before they make plans to destory the castle.\n")  + RESET;
	const std::string objective = BOLDYELLOW + std::string("Destroy the knights hideout, and kill all knights.\n") + RESET;
	std::string status = "";
	if(checkThirdCondition()) {
		status = BOLDGREEN + std::string("Completed\n") + RESET;
	} else {
		status = BOLDYELLOW + std::string("In progress") + RESET;
	}
	
	const std::string questText = YELLOW + std::string("Description: ") + description + YELLOW + std::string("Objective: ") + objective + YELLOW + std::string("Status: ") + status;

	return getObjective(name, questText);
}

bool Quest::checkMainCondition() {
	
	for(int i=0;i<this->roomVec.size();++i) {
		if(this->roomVec.at(i)->getID()==4000) {
			std::vector<Creature*> crea = this->roomVec.at(i)->getCreatureList();
			for(int j=0;j<crea.size();++j) {
				if(crea[j]->gethp() == 0) {
					// dead dragon
					return true;
				} else {
					// alive dragon
					return false;
				}
			}
		}	
	}
}

bool Quest::checkSecondaryCondition() {
	
	for(int i=0;i<this->roomVec.size();++i) {
		if(this->roomVec.at(i)->getID()==2000) {
			std::vector<Creature*> crea = this->roomVec.at(i)->getCreatureList();
			for(int j=0;j<crea.size();++j) {
				if(crea[j]->gethp() != 0) {
					return false;
				}
			}
			// if all creatures in room 2000 are dead, return true
			return true;
		}	
	}
}



bool Quest::checkThirdCondition() {
	
	for(int i=0;i<this->roomVec.size();++i) {

		if((this->roomVec.at(i)->getID()==3000) || (this->roomVec.at(i)->getID()==3001) 
			|| (this->roomVec.at(i)->getID()==3002) || (this->roomVec.at(i)->getID()==3003)) {
			std::vector<Creature*> crea = this->roomVec.at(i)->getCreatureList();
			for(int j=0;j<crea.size();++j) {
				if(crea[j]->gethp() != 0) {
					return false;
				}
			}
		}	
	}
	// if all creatures in the roomid 3000, 3001, 3002, 3003 that are bandits are dead, return true.
	return true;
}

void Quest::setQuest(const int n) {
	if(n==2) {
		this->enableSecondary = true;
	} else if(n == 3) {
		this->enableThird = true;
	}
}

const bool Quest::checkQuest(const int n) const {
	if(n==2) {
		return this->enableSecondary;
	} else if(n == 3) {
		return this->enableThird;
	}
	return false;
}

/*
int main() {
	//Environment *e1 = new Environment("TavernDesc");
	Quest q;
	q.mainQuest();
	std::cout << q.getMainObjective() << std::endl;
}
*/