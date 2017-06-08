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
protected:
	static std::vector<Item*> noobdrops;
	static std::vector<Item*> mediumdrops;
	static std::vector<Item*> prodrops;
	Race* r;
	int hp = 100;
	int str = 10;
	int armorbonus = 0;
	int wepdmg = 1; // unarmed combat
	int droptable = 0;
	int maxhp = 0;
public:
	const int getdroptable() const;
	Creature();
	Creature(Race* race, int droptable);
	~Creature();
	const std::string stats() const;
	const std::string toString() const;
	void hit(int dmg);
	const int gethp() const;
	const int getstr() const;
<<<<<<< HEAD
=======
	void setRace(Race* newrace);
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
};
class Character : public Creature {	// Creature being a lower order base class for example
private:
	Weapon* wep = NULL;
	Helm* helm = NULL;
	Chest* chest = NULL;
	Legs* legs = NULL;
	Profession* p = 0;
	int coins = 1000;
	std::vector<Item*> Items;
	//Room* rum;
public:
<<<<<<< HEAD
=======
	void setRace(Race* newrace);
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	void setItems(std::vector<Item*> in);
	Character(Race* race, Profession* profession);
	~Character();
	std::string toString() const;
	void addItem(Item* it);
	bool equip(Item* it);
	void equip(Weapon* it);
	void equip(Helm* it);
	void equip(Chest* it);
	void equip(Legs* it);
	void unequip(Item* it);
	void drink(Potion* p);
	Weapon* unEquipWep();
	Helm* unEquipHelm();
	Chest* unEquipChest();
	Legs* unEquipLegs();
	void calcBonus();
<<<<<<< HEAD
	void displayitems() const;
	void displayEquippedItems() const;
	void drop(Creature* c);
	const Weapon* getwep() const;
	const Helm* gethelm() const;
	const Chest* getchest() const;
	const Legs* getlegs() const;
	const int getcoins() const;
=======
	void displayitems();
	void displayEquippedItems() const;
	void drop(Creature* c);
	Weapon* getwep() const;
	Helm* gethelm() const;
	Chest* getchest() const;
	Legs* getlegs() const;
	int getcoins() const;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
	void setcoins(int newcoins);
	std::vector<Item*> getItems() const;
};


#endif