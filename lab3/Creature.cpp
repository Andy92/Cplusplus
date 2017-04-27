class Creature {
public:
	Race* r = 0;
	int hp = 100;
	int str = 10;
	Creature(Race* race) {
		r = race;
		hp *= r->rhp;
		str *= r-> rstr;
	}
	string stats() {
		return "hp: " + std::to_string(hp) + " str: " + std::to_string(str);
	}
	string toString() {
		return "race: " + r->toString() + " " + this->stats();
	}
	void hit(int dmg) {
		if(hp-dmg<= 0) {
			hp = 0;
		} else {
			hp -= dmg;
		}
	}
};

class vendor : public Creature {}; //buy items

class questNPC : public Creature {}; //quests / dialogue

class Character : public Creature// Creature being a lower order base class for example
{
public:
	Profession* p = 0;
	Room rum = 0;
	Character(Race* race, Profession* profession, Room *e) : Creature(race) {
		p = profession;
		rum = e;
		hp *= p->php;
		str *= p-> pstr;
	}
	string toString() {
		return "profession: " + p->toString() + " race: " + r->toString() + " " + this->stats();
	}
};