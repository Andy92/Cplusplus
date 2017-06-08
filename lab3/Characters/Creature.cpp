#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Creature.hpp"
<<<<<<< HEAD
/*
=======

>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
std::vector<Item*> Creature::noobdrops = {
	new Weapon(200,std::string("noobwep"), 100),
	new Helm(15, std::string("noobhelm"), 100),
	new Potion(100, std::string("noobpotion"), 100)
};

std::vector<Item*> Creature::mediumdrops = {
	new Weapon(800,std::string("mediumwep"), 1000),
	new Helm(100, std::string("mediumhelm"), 1000),
	new Potion(300, std::string("mediumpotion"), 1000)
};

std::vector<Item*> Creature::prodrops = {
	new Weapon(2000,std::string("prowep"), 2000),
	new Helm(1500, std::string("prohelm"), 2000),
	new Potion(500, std::string("propotion"), 2000)
};
<<<<<<< HEAD
*/
=======

>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	//GETS

const int Creature::getdroptable() const {
	return this->droptable;
}
const int Creature::gethp() const {
	return this->hp;
}
const int Creature::getstr() const {
	return this->str;
}

<<<<<<< HEAD
=======

>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
Creature::Creature(Race* race, int droptable) {
	this->r = race;
	this->hp *= this->r->rhp;
	this->str *= this->r-> rstr;
	this->armorbonus = 0;
	this->droptable = droptable;
}


Creature::~Creature() {
	delete this->r;
<<<<<<< HEAD
=======

	for (auto it = noobdrops.begin(); it != noobdrops.end(); ++it)
	{
		delete *it;
	}

	noobdrops.clear();
	for (auto it = mediumdrops.begin(); it != mediumdrops.end(); ++it)
	{
		delete *it;
	}

	mediumdrops.clear();
	for (auto it = prodrops.begin(); it != prodrops.end(); ++it)
	{
		delete *it;
	}


	prodrops.clear();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
}

Creature::Creature() {
	hp *= this->r->rhp;
	str *= this->r->rstr;
	this->armorbonus = 0;
}
const std::string Creature::stats() const {
	return "\nhp: " + std::to_string(hp) + "\nstr: " + std::to_string(str) + "\narmorbonus: " + std::to_string(armorbonus) + "\nweapondmg: " + std::to_string(wepdmg);
}
const std::string Creature::toString() const {
<<<<<<< HEAD
	return "race: " + this->r->Race::toString() + this->stats();
=======
	return "race: " + this->r->toString() + this->stats();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
}
void Creature::hit(int dmg) {
	int rdmg = dmg - armorbonus;
	if(rdmg < 0)
		rdmg = 0;
	if(hp-rdmg<= 0) {
		hp = 0;
	} else {
		hp -= rdmg;
	}
}

Character::Character(Race* race, Profession* profession) : Creature(race, 1) {
	this->p = profession;
	this->hp *= this->p->php;
	this->str *= this->p->pstr;
	this->maxhp = hp;
	Weapon* w = new Weapon(150, std::string("startwep"), 100);
	Helm* h = new Helm(10, std::string("starthelm"), 100);
	Potion* p = new Potion(100, std::string("noobpot"), 100);
	this->addItem(p);
	this->addItem(h);
	this->addItem(w);
}

<<<<<<< HEAD
=======
void Character::setRace(Race* newrace) {
	this->hp /= this->r->rhp;
	this->str /= this->r-> rstr;

	delete this->r;
	this->r = newrace;
	this->hp = 100*this->r->rhp*this->p->php;
	this->str *= this->r->rstr*this->p->pstr;
	this->maxhp = hp;
}

>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
//destructor

Character::~Character() {
	delete this->wep;
	delete this->helm;
	delete this->legs;
	delete this->chest;
	delete this->p;
	for(int i = 0; i < Items.size(); ++i) {
		delete this->Items.at(i);
	}
<<<<<<< HEAD
	/*
	for(int i = 0; i < noobdrops.size(); ++i) {
		delete noobdrops.at(i);
	}

	for(int i = 0; i < mediumdrops.size(); ++i) {
		delete noobdrops.at(i);
	}
	
	for(int i = 0; i < prodrops.size(); ++i) {
		delete noobdrops.at(i);
	}
	*/
}
std::string Character::toString() const {
	return "profession: " + this->p->Profession::toString() + "\nrace: " + this->r->Race::toString() + " " + this->stats();
=======
}
std::string Character::toString() const {
	return "profession: " + this->p->Profession::toString() + "\nrace: " + this->r->toString() + " " + this->stats();
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
}

void Character::addItem(Item* it) {
	this->Items.push_back(it);
}

bool Character::equip(Item* it) {
	int a = it->getid();
	switch(a) {
			case 1 : if(this->getwep() != NULL) {std::cout << "unequip current weapon before equipping a new one" << std::endl; return false;} 
			this->equip(static_cast<Weapon*>(it)); // might remove data bc item vector
			break;
			case 3 : if(this->gethelm() != NULL) {std::cout << "unequip current helm before equipping a new one" << std::endl; return false;}
			this->equip(static_cast<Helm*>(it)); // might remove data bc item vector
			break;
			case 4 : if(this->getchest() != NULL) {std::cout << "unequip current chest before equipping a new one" << std::endl; return false;}
			this->equip(static_cast<Chest*>(it)); // might remove data bc item vector
			break;
			case 5 : if(this->getlegs() != NULL) {std::cout << "unequip current legs before equipping a new one" << std::endl; return false;}
			this->equip(static_cast<Legs*>(it)); // might remove data bc item vector
			break;
			case 6 : this->drink(static_cast<Potion*>(it));
			break;
		}
		return true;
	}
void Character::drink(Potion* p) {
	int a = this->hp + p->getheal();
	int printheal = 0;
	if(a <= this->maxhp) {
		printheal = p->getheal();
		this->hp += p->getheal();
	}
	else {
		printheal = (this->maxhp - this->hp);
		this->hp = this->maxhp;
	}
	std::cout << "You drink the potion: " << p->desc() << " and it heals you for " << printheal << " hp";
}

void Character::calcBonus() {
	if(this->wep != NULL)
		this->wepdmg = this->wep->getdmg();
	else {
		this->wepdmg = 1;
	}
	if(this->helm != NULL && this->chest != NULL && this->legs != NULL) {
		this->armorbonus = this->helm->getarmor() + this->chest->getarmor() + this->legs->getarmor();
	}
	else if(this->helm != NULL && this->chest != NULL) {
		this->armorbonus = this->helm->getarmor() + this->chest->getarmor();
	}
	else if(this->chest != NULL && this->legs != NULL) {
		this->armorbonus = this->chest->getarmor() + this->legs->getarmor();
	}
	else if(this->helm != NULL && this->legs != NULL) {
		this->armorbonus = this->helm->getarmor() + this->legs->getarmor();
	}
	else if(this->helm != NULL) {
		this->armorbonus = this->helm->getarmor();
	}
	else if(this->chest != NULL) {
		this->armorbonus = this->chest->getarmor();
	}
	else if(this->legs != NULL) {
		this->armorbonus = this->legs->getarmor();
	}
	else {
		this->armorbonus = 0;
	}
}
void Character::equip(Weapon* it) {
	this->wep = it;
	std::cout << "you equipped a wep" << std::endl;
	this->calcBonus();
}
void Character::equip(Helm* it) {
	this->helm = it;
	std::cout << "you equipped an helm" << std::endl;
	this->calcBonus();
}
void Character::equip(Chest* it){
	this->chest = it;
	std::cout << "you equipped chestarmor" << std::endl;
	this->calcBonus();
}
void Character::equip(Legs* it){
	this->legs = it;
	std::cout << "you equipped legarmor" << std::endl;
	this->calcBonus();
}
Weapon* Character::unEquipWep() {
	if(this->wep == NULL) {
		std::cout << "you have no weapon equipped at the moment" << std::endl;
		return NULL;
	}
	Weapon* w = this->wep;
	this->wep = NULL;
	std::cout << "you unequipped a wep" << std::endl;
	this->calcBonus();
	return w;
}
Helm* Character::unEquipHelm() {
	if(this->helm == NULL) {
		std::cout << "you have no helm equipped at the moment" << std::endl;
		return NULL;
	}
	Helm* h = this->helm;
	this->helm = NULL; // destructor?
	std::cout << "you unequipped an helm" << std::endl;
	this->calcBonus();
	return h;
}
Chest* Character::unEquipChest(){
	if(this->chest == NULL) {
		std::cout << "you have no chest equipped at the moment" << std::endl;
		return NULL;
	}
	Chest* c = this->chest;
	this->chest = NULL; // destructor?
	std::cout << "you unequipped chestarmor" << std::endl;
	this->calcBonus();
	return c;
}
Legs* Character::unEquipLegs(){
	if(this->legs == NULL) {
		std::cout << "you have no legs equipped at the moment" << std::endl;
		return NULL;
	}
	Legs* l = this->legs;
	this->legs = NULL; // destructor?
	std::cout << "you unequipped legarmor" << std::endl;
	this->calcBonus();
	return l;

}
<<<<<<< HEAD
void Character::displayitems() const {
=======
void Character::displayitems() {
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	for(int i =0; i < this->Items.size() ;++i) {
		std::cout << "press: " << i << " to equip or use item: " << this->Items.at(i)->desc() << std::endl;
	}
}
void Character::displayEquippedItems() const {
	std::cout << "You have " << this->coins << " coins available" << std::endl;
	if(this->wep != NULL)
		std::cout << this->wep->desc() << "1 for wep" << std::endl;
	if(this->helm != NULL)
		std::cout << this->helm->desc() << "2 for helm" << std::endl;
	if(this->chest != NULL)
		std::cout << this->chest->desc() << "3 for chest" << std::endl;
	if(this->legs != NULL)
		std::cout << this->legs->desc() << "4 for legs" << std::endl;
}
void Character::drop(Creature* c) {
<<<<<<< HEAD
	/*
=======
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	int randnum = 0;
	srand (time(NULL));
	switch(c->getdroptable()) {
		case 1 : randnum = rand() % noobdrops.size();
		std::cout << "You looted the creature that you have defeated and found: " << noobdrops.at(randnum)->desc() << std::endl <<  " and you also found 100 coins";
<<<<<<< HEAD
		this->Items.push_back(noobdrops.at(randnum));
=======
		this->Items.push_back(c->noobdrops.at(randnum));
		c->noobdrops.erase(c->noobdrops.begin() + randnum);
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		this->coins += 100;
		break;
		case 2 : randnum = rand() % mediumdrops.size();
		std::cout << "You looted the creature that you have defeated and found: " << mediumdrops.at(randnum)->desc() << std::endl <<  " and you also found 500 coins";;
<<<<<<< HEAD
		this->Items.push_back(mediumdrops.at(randnum));
=======
		this->Items.push_back(c->mediumdrops.at(randnum));
		c->mediumdrops.erase(c->mediumdrops.begin() + randnum);
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
		this->coins += 500;
		break;
		case 3 : randnum = rand() % prodrops.size();
		std::cout << "You looted the creature that you have defeated and found: " << prodrops.at(randnum)->desc() << std::endl <<  " and you also found 1000 coins";;
<<<<<<< HEAD
		this->Items.push_back(prodrops.at(randnum));
		this->coins += 1000;
		break;
	}
	*/
=======
		this->Items.push_back(c->prodrops.at(randnum));
		c->prodrops.erase(c->mediumdrops.begin() + randnum);
		this->coins += 1000;
		break;
		case 4 : std::cout << "You looted the creature that you have defeated and found something extra interesting, a KnightsSword" << std::endl;
		this->Items.push_back(new KnightsSword(300, std::string("knightsSword"), 3000));
		break;
		case 5 : std::cout << "You have looted the creature that you have defeated and found something extra interesting, a DragonTooth" << std::endl;
		this->Items.push_back(new DragonTooth(300, std::string("DragonTooth"), 3000));
		break;
	}
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
}

std::vector<Item*> Character::getItems() const {
	return this->Items;
}

void Character::setItems(std::vector<Item*> in) {
	this->Items = in;
}
<<<<<<< HEAD
const Weapon* Character::getwep() const {
	return this->wep;
}
const Helm* Character::gethelm() const {
	return this->helm;
}
const Chest* Character::getchest() const {
	return this->chest;
}
const Legs* Character::getlegs() const {
	return this->legs;
}
const int Character::getcoins() const {
=======
Weapon* Character::getwep() const {
	return this->wep;
}
Helm* Character::gethelm() const {
	return this->helm;
}
Chest* Character::getchest() const {
	return this->chest;
}
Legs* Character::getlegs() const {
	return this->legs;
}
int Character::getcoins() const {
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	return this->coins;
}

void Character::setcoins(int newcoins) {
	this->coins = newcoins;
}

