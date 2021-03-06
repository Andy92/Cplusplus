#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
//#include "Environment/Room.cpp"
#include "Environment/Room.hpp"



#ifndef QUEST_HPP
#define QUEST_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m" /* Bold White */

class Quest {

private:

	// Copy of game map
	std::vector<Room*> roomVec;
	// make it a list of booleans.
	bool enableMain = true;
	bool enableSecondary = false;
	bool enableThird = false;
	
public:
	Quest(std::vector<Room*> room);
	const std::string getMainObjective();
	const std::string getSecondaryObjective();
	const std::string getThirdObjective();
	const std::string getObjective(const std::string qN, const std::string qT) const;
	bool checkMainCondition();
	bool checkSecondaryCondition();
	bool checkThirdCondition();
	void setQuest(const int n);
	const bool checkQuest(const int n) const;
	~Quest();
<<<<<<< HEAD
=======
	Room* getSpecificRoom(int id) const;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
};







#endif