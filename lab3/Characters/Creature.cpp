#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Creature.hpp"

std::vector<Item*> Creature::noobdrops = {
	new Weapon(200,std::string("noobwep")),
	new Helm(15, std::string("noobhelm")),
	new Potion(100, std::string("noobpotion"))
};

std::vector<Item*> Creature::mediumdrops = {
	new Weapon(800,std::string("mediumwep")),
	new Helm(100, std::string("mediumhelm")),
	new Potion(300, std::string("mediumpotion"))
};

std::vector<Item*> Creature::prodrops = {
	new Weapon(2000,std::string("prowep")),
	new Helm(1500, std::string("prohelm")),
	new Potion(500, std::string("propotion"))
};

	//GETS

const int Creature::getdroptable() {
	return this->droptable;
}
const int Creature::gethp() {
	return this->hp;
}
const int Creature::getstr() {
	return this->str;
}

Creature::Creature(Race* race, int droptable) {
	this->r = race;
	this->hp *= this->r->rhp;
	this->str *= this->r-> rstr;
	this->armorbonus = 0;
	this->droptable = droptable;
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
	return "race: " + this->r->Race::toString() + this->stats();
}
void Creature::hit(int dmg) {
	int rdmg = dmg - armorbonus;
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
	Potion* p = new Potion(100, std::string("noobpot"));
	this->addItem(p);
	this->addItem(h);
	this->addItem(w);
}
std::string Character::toString() const {
	return "profession: " + this->p->Profession::toString() + "\nrace: " + this->r->Race::toString() + " " + this->stats();
}

void Character::addItem(Item* it) {
	this->Items.push_back(it);
}

void Character::equip(Item* it) {
	int a = it->getid();
	switch(a) {
			case 1 : this->equip(dynamic_cast<Weapon*>(it)); // might remove data bc item vector
			break;
			case 2 : this->equip(dynamic_cast<Armor*>(it)); // might remove data bc item vector
			break;
			case 3 : this->equip(dynamic_cast<Helm*>(it)); // might remove data bc item vector
			break;
			case 4 : this->equip(dynamic_cast<Chest*>(it)); // might remove data bc item vector
			break;
			case 5 : this->equip(dynamic_cast<Legs*>(it)); // might remove data bc item vector

			case 6 : this->drink(dynamic_cast<Potion*>(it));
			break;
		}
	}
void Character::drink(Potion* p) {
	int a = this->hp + p->getheal();
	if(a <= this->maxhp) {
		this->hp += p->getheal();
	}
	std::cout << "You drink the potion: " << p->desc() << " and it heals you for";
}

void Character::calcBonus() {
	if(this->wep != NULL)
		this->wepdmg = this->wep->getdmg();
	else {
		this->wepdmg = 1;
	}
	if(this->helm != NULL && this->chest != NULL && this->legs != NULL)
		this->armorbonus = this->helm->getarmor() + this->chest->getarmor() + this->legs->getarmor();

	if(this->helm != NULL && this->chest != NULL) {
		this->armorbonus = this->helm->getarmor() + this->chest->getarmor();
	}
	if(this->chest != NULL && this->legs != NULL) {
		this->armorbonus = this->chest->getarmor() + this->legs->getarmor();
	}
	if(this->helm != NULL && this->legs != NULL) {
		this->armorbonus = this->helm->getarmor() + this->legs->getarmor();
	}
	if(this->helm != NULL) {
		this->armorbonus = this->helm->getarmor();
	}
	if(this->chest != NULL) {
		this->armorbonus = this->chest->getarmor();
	}
	if(this->legs != NULL) {
		this->armorbonus = this->legs->getarmor();
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
	Weapon* w = this->wep;
	this->wep = NULL;
	std::cout << "you unequipped a wep" << std::endl;
	this->calcBonus();
	return w;
}
Helm* Character::unEquipHelm() {
	Helm* h = this->helm;
	this->helm = NULL; // destructor?
	std::cout << "you unequipped an helm" << std::endl;
	this->calcBonus();
	return h;
}
Chest* Character::unEquipChest(){
	Chest* c = this->chest;
	this->chest = NULL; // destructor?
	std::cout << "you unequipped chestarmor" << std::endl;
	this->calcBonus();
	return c;
}
Legs* Character::unEquipLegs(){
	Legs* l = this->legs;
	this->legs = NULL; // destructor?
	std::cout << "you unequipped legarmor" << std::endl;
	this->calcBonus();
	return l;

}
void Character::displayitems() const {
	for(int i =0; i < this->Items.size() ;++i) {
		std::cout << "press: " << i << " to equip or use item: " << this->Items.at(i)->desc() << std::endl;
	}
}
void Character::displayEquippedItems() const {
	if(this->wep != NULL)
		std::cout << this->wep->desc() << "1 for wep";
	if(this->helm != NULL)
		std::cout << this->helm->desc() << "2 for helm";
	if(this->chest != NULL)
		std::cout << this->chest->desc() << "3 for chest";
	if(this->legs != NULL)
		std::cout << this->legs->desc() << "4 for legs";
}
void Character::drop(Creature* c) {
	int randnum = 0;
	srand (time(NULL));
	switch(c->getdroptable()) {
		case 1 : randnum = rand() % noobdrops.size();
		std::cout << "You looted the creature that you have defeated and found: " << noobdrops.at(randnum)->desc() << " and 100 coins";
		this->Items.push_back(noobdrops.at(randnum));
		this->coins += 100;
		break;
		case 2 : randnum = rand() % mediumdrops.size();
		std::cout << "You looted the creature that you have defeated and found: " << mediumdrops.at(randnum)->desc() << " and 500 coins";
		this->Items.push_back(mediumdrops.at(randnum));
		this->coins += 500;
		break;
		case 3 : randnum = rand() % prodrops.size();
		std::cout << "You looted the creature that you have defeated and found: " << prodrops.at(randnum)->desc() << " and 1000 coins";
		this->Items.push_back(prodrops.at(randnum));
		this->coins += 1000;
		break;
	}
}

std::vector<Item*> Character::getItems() const {
	return this->Items;
}

void Character::setItems(std::vector<Item*> in) {
	this->Items = in;
}
const Weapon* Character::getwep() const {
	return this->wep;
}
const int Character::getcoins() const {
	return this->coins;
}

void Character::setcoins(int newcoins) {
	this->coins = newcoins;
}