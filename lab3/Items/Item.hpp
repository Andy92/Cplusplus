#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#ifndef Item_HPP
#define Item_HPP

class Item {
protected:
	int value;
	int id;
	std::string name;
public:
	const int getid();
	const int getvalue();
	virtual std::string desc();
	void setValue(int value);
};

class Potion : public Item {
private:
	int heal;
public:
	Potion(int heal, std::string name);
	std::string desc();
	const int getheal();
};

class Weapon : public Item {
private:
	int dmg;
public:
	Weapon(int dmg, std::string name);
	Weapon(int dmg, std::string name, int value);
	std::string desc();
	const int getdmg() const;
	const Weapon* get() const;
};

class Armor : public Item {
protected:
	int armor;
public:
	const int getarmor();
	Armor(int armor, std::string name);
	Armor(int armor, std::string name, int value);
	std::string desc();
};

class Helm : public Armor {
public:
	Helm(int armor, std::string name, int value);
	Helm(int armor, std::string name);
};
class Chest : public Armor {
public:
	Chest(int armor, std::string name, int value);
	Chest(int armor, std::string name);
};
class Legs : public Armor {
public:
	Legs(int armor, std::string name, int value);
	Legs(int armor, std::string name);
};

#endif