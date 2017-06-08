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
	const int getid() const;
	const int getvalue() const;
	const virtual std::string desc() const;
	void setValue(int value);
};

class Potion : public Item {
private:
	int heal;
public:
	Potion(int heal, std::string name);
	Potion(int heal, std::string name, int value);
	const std::string desc() const;
	const int getheal() const;
};

class Weapon : public Item {
private:
	int dmg;
public:
	Weapon(int dmg, std::string name);
	Weapon(int dmg, std::string name, int value);
	const std::string desc() const;
	const int getdmg() const;
	const Weapon* get() const;
<<<<<<< HEAD
};

=======
	const virtual int spec() const;
};

class KnightsSword : public Weapon {
private:
	int dmg;
public:
	const std::string desc() const;
	KnightsSword(int dmg, std::string name, int value);
	const virtual int spec() const;
};


class DragonTooth : public Weapon {
private:
	int dmg;
public:
	const std::string desc() const;
	DragonTooth(int dmg, std::string name, int value);
	const virtual int spec() const;
};


class GodSword : public Weapon {
private:
	int dmg;
public:
	const std::string desc() const;
	GodSword(int dmg, std::string name, int value);
	const virtual int spec() const;
};


>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
class Armor : public Item {
protected:
	int armor;
public:
	const int getarmor() const;
	Armor(int armor, std::string name);
	Armor(int armor, std::string name, int value);
	const std::string desc() const;
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