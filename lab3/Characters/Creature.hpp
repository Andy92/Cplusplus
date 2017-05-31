#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Race.hpp"
#include "Profession.hpp"
#include "../Items/Item.hpp"

#ifndef CREATURE_HPP
#define CREATURE_HPP
class Creature {
public:
	static std::vector<Item*> noobdrops;
	static std::vector<Item*> mediumdrops;
	static std::vector<Item*> prodrops;
	Race* r;
	int hp = 100;
	int str = 10;
	int armorbonus = 0;
	int wepdmg = 1; // unarmed combat
	int droptable = 0;
	Creature();
	Creature(Race* race, int droptable);
	std::string stats();
	std::string toString();
	void hit(int dmg);
	void drop(Creature* c);
};
class Character : public Creature {	// Creature being a lower order base class for example
public:
	Weapon* wep = NULL;
	Helm* helm = NULL;
	Chest* chest = NULL;
	Legs* legs = NULL;
	Profession* p = 0;
	std::vector<Item*> Items;
	//Room* rum;
	Character(Race* race, Profession* profession);
	std::string toString();
	void addItem(Item* it);
	void equip(Item* it);
	void equip(Weapon* it);
	void equip(Helm* it);
	void equip(Chest* it);
	void equip(Legs* it);
	void unequip(Item* it);
	Weapon* unEquipWep();
	Helm* unEquipHelm();
	Chest* unEquipChest();
	Legs* unEquipLegs();
	void calcBonus();
	void displayitems();
	void displayEquippedItems();
};


#endif