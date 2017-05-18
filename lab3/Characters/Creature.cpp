#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Creature.hpp"

	Creature::Creature(Race* race) {
		this->r = race;
		hp *= this->r->rhp;
		str *= this->r-> rstr;
	}
	Creature::Creature() {
		hp *= this->r->rhp;
		str *= this->r-> rstr;
	}
	std::string Creature::stats() {
		return "hp: " + std::to_string(hp) + " str: " + std::to_string(str);
	}
	std::string Creature::toString() {
		return "race: " + this->r->Race::toString() + " " + this->stats();
	}
	void Creature::hit(int dmg) {
		if(hp-dmg<= 0) {
			hp = 0;
		} else {
			hp -= dmg;
		}
	}

Character::Character(Race* race, Profession* profession) : Creature(race) {
		this->p = profession;
		//rum = e;
		hp *= this->p->php;
		str *= this->p->pstr;
	}
	std::string Character::toString() {
		return "profession: " + this->p->Profession::toString() + " race: " + this->r->Race::toString() + " " + this->stats();
	}
