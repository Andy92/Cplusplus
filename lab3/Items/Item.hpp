#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#ifndef Item_HPP
#define Item_HPP

class Item {
public:
	int value;
	int id;
	std::string name;
	virtual std::string desc();
};

class Weapon : public Item {
public:
	Weapon* get();
	int dmg;
	Weapon(int dmg, std::string name);
	std::string desc();
};

class Armor : public Item {
public:
	int armor; 
	Armor(int armor, std::string name);
	std::string desc();
};

class Helm : public Armor {
public:
	Helm(int armor, std::string name);
};
class Chest : public Armor {
public:
	Chest(int armor, std::string name);
};
class Legs : public Armor {
public:
	Legs(int armor, std::string name);
};

#endif