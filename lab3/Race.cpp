#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
class Race
{
public:
string id;
float rhp = 0;
float rstr = 0;
	Race(string identifier){
		this->id = identifier;
	}
	string toString() {
		return this->id;
	}   
};

class Human : public Race
{
public:
	Human() : Race("Human") {
		rhp = 1.1;
		rstr = 1.1;
	}

};

class Orc: public Race
{
public:
	Orc() : Race("Orc") {
		rhp = 1.3;
		rstr = 1.4;
	}    
};