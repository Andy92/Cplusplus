#include "Quest.hpp"


/*
*  This is a quest file, where all quests will be.
*
*/



Quest::Quest(std::vector<Room*> room) {
	this->roomVec = room;
}

void Quest::mainQuest() {
	std::cerr << GREEN << "err" << RESET << std::endl;
}

std::string Quest::getObjective(std::string qN, std::string qT) {
	std::string questName = qN;
	std::string questText = qT;
	std::string text = YELLOW + std::string("########## ") + questName + std::string(" ################\n") + questText + YELLOW + std::string("\n######################################") + RESET;


	//YELLOW + std::string("########## MAIN QUEST ################\nDescription: " + description + YELLOW + "\nObjective: " + objective + YELLOW + "\n######################################") + RESET;

	return text;
}

std::string Quest::getMainObjective() {

	std::string name = "MAIN QUEST";
	std::string description = BOLDCYAN + std::string("The orc in the first room of the game has been bothering me, finish him.\n")  + RESET;
	std::string objective = BOLDYELLOW + std::string("Kill the orc in roomID 0 in environment tavern.\n") + RESET;
	std::string status = "";
	if(checkMainCondition()) {
		status = BOLDGREEN + std::string("Completed\n") + RESET;
	} else {
		status = BOLDYELLOW + std::string("In progress") + RESET;
	}
	
	std::string questText = YELLOW + std::string("Description: ") + description + YELLOW + std::string("Objective: ") + objective + YELLOW + std::string("Status: ") + status;

	return getObjective(name, questText);
}


std::string Quest::getSecondaryObjective() {

	std::string name = "SECONDARY QUEST";
	std::string description = BOLDCYAN + std::string("Finish off all the creatures in tavern.\n")  + RESET;
	std::string objective = BOLDYELLOW + std::string("Kill all creatures in all rooms in tavern.\n") + RESET;
	std::string status = "";
	if(completed()) {
		status = BOLDGREEN + std::string("Completed\n") + RESET;
	} else {
		status = BOLDYELLOW + std::string("In progress") + RESET;
	}
	
	std::string questText = YELLOW + std::string("Description: ") + description + YELLOW + std::string("Objective: ") + objective + YELLOW + std::string("Status: ") + status;

	return getObjective(name, questText);
}


bool Quest::checkMainCondition() {
	
	for(int i=0;i<this->roomVec.size();++i) {
		if(this->roomVec.at(i)->getID()==1000) {
			std::vector<Creature*> crea = this->roomVec.at(i)->getCreatureList();
			for(int j=0;j<crea.size();++j) {
				if(crea[j]->hp == 0) {
					return true;
				} else {
					return false;
				}
			}
		}
		
	}
	
}

bool Quest::completed() {
	return true;
}

/*
int main() {
	//Environment *e1 = new Environment("TavernDesc");
	Quest q;
	q.mainQuest();
	std::cout << q.getMainObjective() << std::endl;
}
*/