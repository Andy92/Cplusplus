#include "Item.hpp"

std::string Item::desc() {
	std::string ret = "this is an item \n";
	return ret;
}
//weapon.cpp
Weapon::Weapon(int dmg, std::string name) {
	this->dmg = dmg;
	this->name = name;
	this->id = 1;
}
Weapon* Weapon::get() {
	return this;
}
std::string Weapon::desc()  {
	std::string ret = "weapon: " + name + "\n";
	return ret;
}
//armor.cpp
Armor::Armor(int armor, std::string name) {
	this->armor = armor;
	this->name = name;
	this->id = 2;
}

Helm::Helm(int armor, std::string name) : Armor(armor, name) {
	this->id = 3;
}
Chest::Chest(int armor, std::string name) : Armor(armor, name) {
	this->id = 4;
}
Legs::Legs(int armor, std::string name) : Armor(armor, name) {
	this->id = 5;
}

std::string Armor::desc() {
	std::string ret = "armor: " + name + "\n";
	return ret;
}