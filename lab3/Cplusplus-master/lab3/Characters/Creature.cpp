#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Creature.hpp"
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


Creature::Creature(Race* race, int droptable) {
	this->r = race;
	this->hp *= this->r->rhp;
	this->str *= this->r-> rstr;
	this->armorbonus = 0;
	this->droptable = droptable;
}


Creature::~Creature() {
	delete this->r;
}

Creature::Creature() {
	hp *= this->r->rhp;
	str *= this->r->rstr;
	this->armorbonus = 0;
}

void Creature::setstr(int str) {
	if(str < 0) this->str = 0;
	else this->str = str;
}

const int Creature::getmaxstr() const {
	return this->maxstr;
}

const std::string Creature::stats() const {
	return "\nhp: " + std::to_string(hp) + "\nstr: " + std::to_string(str) + "\narmorbonus: " + std::to_string(armorbonus) + "\nweapondmg: " + std::to_string(wepdmg);
}
const std::string Creature::toString() const {
	return "race: " + this->r->toString() + this->stats();
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
	this->maxstr = str;
	Weapon* w = new Weapon(150, std::string("startwep"), 100);
	Helm* h = new Helm(10, std::string("starthelm"), 100);
	Potion* p = new Potion(100, std::string("noobpot"), 100);
	this->addItem(p);
	this->addItem(h);
	this->addItem(w);
}

void Character::setRace(Race* newrace) {
	this->hp /= this->r->rhp;
	this->str /= this->r-> rstr;

	delete this->r;
	this->r = newrace;
	this->hp = 100*this->r->rhp*this->p->php;
	this->str *= this->r->rstr*this->p->pstr;
	this->maxhp = hp;
}

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
}
std::string Character::toString() const {
	return "profession: " + this->p->Profession::toString() + "\nrace: " + this->r->toString() + " " + this->stats();
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
	delete p;
}
void Character::heal(int heal) {
	int a = this->hp + heal;
	int printheal = 0;
	if(a <= this->maxhp) {
		printheal = heal;
		this->hp += heal;
	}
	else {
		printheal = (this->maxhp - this->hp);
		this->hp = this->maxhp;
	}
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
void Character::displayitems() {
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
	int randnum = 0;
	srand (time(NULL));
	
	switch(c->droptable) {
		
		
		
		case 1 : randnum = (rand() % 3) + 1;
		std::cout << "You looted the creature that you have defeated and found an item " << std::endl <<  " and you also found 100 coins";
		switch(randnum) {
			case 1:
			this->Items.push_back(new Weapon(100, "noobwep", 100));
			break;
			case 2:
			this->Items.push_back(new Helm(10, "noobhelm", 100));
			break;
			case 3:
			this->Items.push_back(new Potion(100, "noobpot", 100));
			break;
		}
		this->coins += 100;
		break;
		case 2 : randnum = (rand() % 3) + 1;
		std::cout << "You looted the creature that you have defeated and found an item" << std::endl <<  " and you also found 500 coins";;
		switch(randnum) {
			case 1:
			this->Items.push_back(new Weapon(100, "mediumwep", 100));
			break;
			case 2:
			this->Items.push_back(new Helm(10, "mediumhelm", 100));
			break;
			case 3:
			this->Items.push_back(new Potion(100, "mediumpot", 100));
			break;
		}
		this->coins += 500;
		break;
		case 3 : randnum = (rand() % 3) + 1;//rand() % prodrops.size();
		std::cout << "You looted the creature that you have defeated and found an item" << std::endl <<  " and you also found 1000 coins";;
		switch(randnum) {
			case 1:
			this->Items.push_back(new Weapon(1000, "prowep", 1000));
			break;
			case 2:
			this->Items.push_back(new Helm(100, "prohelm", 1000));
			break;
			case 3:
			this->Items.push_back(new Potion(400, "propot", 1000));
			break;
		}
		this->coins += 1000;
		break;
		
		case 4 : std::cout << "You looted the creature that you have defeated and found something extra interesting, a KnightsSword" << std::endl;
		this->Items.push_back(new KnightsSword(300, std::string("knightsSword"), 3000));
		break;
		
		case 5 : std::cout << "You have looted the creature that you have defeated and found something extra interesting, a DragonTooth" << std::endl;
		this->Items.push_back(new DragonTooth(300, std::string("DragonTooth"), 3000));
		break;
		
		}
	
}

std::vector<Item*> Character::getItems() const {
	return this->Items;
}

void Character::setItems(std::vector<Item*> in) {
	this->Items = in;
}
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
	return this->coins;
}

void Character::setcoins(int newcoins) {
	this->coins = newcoins;
}

