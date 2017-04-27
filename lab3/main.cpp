#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#include "Profession.cpp"
#include "Race.cpp"
#include "Creature.cpp"
#include "environment.cpp"


void combat1v1(Character *first, Creature *second) {
	string winner;
	while(true) {
		first->hit(second->str);
		if(first->hp <= 0) {
			winner = second->r->id;
			break;
		}
		second->hit(first->str);
		if(second->hp <= 0) {
			winner = first->r->id;
			break;
		}
	}
	cout << winner << endl;
}

void Game() {
	Environment *e = new Environment();
	Room *rum = new Room(e);
	Character *charr = new Character(new Human(), new Warrior(), rum);
	Creature  *creat = new Creature(new Orc());
	cout << charr->toString() << endl;
  	cout << creat->toString() << endl;

  	
  	combat1v1(charr, creat);
  	cout << charr->toString() << endl;
  	cout << creat->toString() << endl;

}



int main() {
	cout << "\033[33mStarting game\033[37m" << endl;
	Game();
	cout << "\033[33mGame ended\033[37m" << endl;
}