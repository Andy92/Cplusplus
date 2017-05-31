#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Creature.hpp"

std::vector<Item*> Creature::noobdrops = {
		new Weapon(200,std::string("noobwep")),
		new Helm(15, std::string("noobhelm"))
	};

std::vector<Item*> Creature::mediumdrops = {
		new Weapon(800,std::string("mediumwep")),
		new Helm(100, std::string("mediumhelm"))
	};

std::vector<Item*> Creature::prodrops = {
		new Weapon(2000,std::string("prowep")),
		new Helm(1500, std::string("prohelm"))
	};

	Creature::Creature(Race* race, int droptable) {
		this->r = race;
		hp *= this->r->rhp;
		str *= this->r-> rstr;
		this->armorbonus = 0;
		this->droptable = droptable;
	}
	Creature::Creature() {
		hp *= this->r->rhp;
		str *= this->r->rstr;
		this->armorbonus = 0;
	}
	void Creature::drop(Creature* c) {
		int randnum = 0;
		srand (time(NULL));
		std::cout << "testasfnfeqfeqnn " << c->droptable << " sadsfdafad";
		switch(c->droptable) {
			case 1 : randnum = rand() % noobdrops.size();
				std::cout << randnum << noobdrops.at(randnum)->desc() << std::endl;
				break;
			case 2 : randnum = rand() % mediumdrops.size();
				std::cout << randnum << mediumdrops.at(randnum)->desc() << std::endl;
				break;
			case 3 : randnum = rand() % prodrops.size();
				std::cout << "testasdasdasdasdasd" << randnum << prodrops.at(randnum)->desc() << std::endl;
				break;

		}
		//std::cout << "the creature: " << std::endl << c->toString() << "has fallen" << std::endl;
	}
	std::string Creature::stats() {
		return "\nhp: " + std::to_string(hp) + "\nstr: " + std::to_string(str) + "\narmorbonus: " + std::to_string(armorbonus) + "\nweapondmg: " + std::to_string(wepdmg);
	}
	std::string Creature::toString() {
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
		//rum = e;
		hp *= this->p->php;
		str *= this->p->pstr;
		Weapon* w = new Weapon(150, std::string("startwep"));
		Helm* h = new Helm(10, std::string("starthelm"));
		this->addItem(h);
		this->addItem(w);
	}
	std::string Character::toString() {
		return "profession: " + this->p->Profession::toString() + "\nrace: " + this->r->Race::toString() + " " + this->stats();
	}
	
	void Character::addItem(Item* it) {
		this->Items.push_back(it);
	}

	void Character::equip(Item* it) {
		int a = it->id;
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
				break;
		}
	}
	void Character::calcBonus() {
		if(this->wep != NULL)
			this->wepdmg = this->wep->dmg;
		else {
			this->wepdmg = 1;
		}
		if(this->helm != NULL && this->chest != NULL && this->legs != NULL)
			this->armorbonus = this->helm->armor + this->chest->armor + this->legs->armor;

		if(this->helm != NULL && this->chest != NULL) {
			this->armorbonus = this->helm->armor + this->chest->armor;
		}
		if(this->chest != NULL && this->legs != NULL) {
			this->armorbonus = this->chest->armor + this->legs->armor;
		}
		if(this->helm != NULL && this->legs != NULL) {
			this->armorbonus = this->helm->armor + this->legs->armor;
		}
		if(this->helm != NULL) {
			this->armorbonus = this->helm->armor;
		}
		if(this->chest != NULL) {
			this->armorbonus = this->chest->armor;
		}
		if(this->legs != NULL) {
			this->armorbonus = this->legs->armor;
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
	void Character::displayitems(){
		for(int i =0; i < this->Items.size() ;++i) {
			std::cout << "press: " << i << " to equip or use item: " << this->Items.at(i)->desc();
		}
	}
	void Character::displayEquippedItems() {
	if(this->wep != NULL)
		std::cout << this->wep->desc() << "1 for wep";
	if(this->helm != NULL)
		std::cout << this->helm->desc() << "2 for helm";
	if(this->chest != NULL)
		std::cout << this->chest->desc() << "3 for chest";
	if(this->legs != NULL)
		std::cout << this->legs->desc() << "4 for legs";
	}