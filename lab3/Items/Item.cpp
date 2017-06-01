#include "Item.hpp"
//item.cpp
std::string Item::desc() {
	std::string ret = "this is an item \n";
	return ret;
}
void Item::setValue(int value) {
	this->value = value;
}
const int Item::getvalue() {
	return this->value;
}
const int Item::getid() {
	return this->id;
}
//potion.cpp
Potion::Potion(int heal, std::string name) {
	this->heal = heal;
	this->name = name;
	this->id = 6;
}
std::string Potion::desc()  {
	std::string ret = "Potion: " + name + " ";
	return ret;
}
const int Potion::getheal() {
	return this->heal;
}
//weapon.cpp
Weapon::Weapon(int dmg, std::string name) {
	this->dmg = dmg;
	this->name = name;
	this->id = 1;
}
Weapon::Weapon(int dmg, std::string name, int value) {
	this->dmg = dmg;
	this->name = name;
	this->value = value;
	this->id = 1;
}
const Weapon* Weapon::get() const {
	return this;
}
const int Weapon::getdmg() const {
	return this->dmg;
}
std::string Weapon::desc()  {
	std::string ret = "weapon: " + name + " ";
	return ret;
}
//armor.cpp
Armor::Armor(int armor, std::string name) {
	this->armor = armor;
	this->name = name;
	this->id = 2;
}
Armor::Armor(int armor, std::string name, int value) {
	this->armor = armor;
	this->name = name;
	this->id = 2;
	this->value = value;
}
const int Armor::getarmor() {
	return this->armor;
}

std::string Armor::desc() {
	std::string ret = "armor: " + name + " ";
	return ret;
}

//helm.cpp
Helm::Helm(int armor, std::string name) : Armor(armor, name) {
	this->id = 3;
}
Helm::Helm(int armor, std::string name, int value) : Armor(armor, name, value) {
	this->id = 3;
}
//chest.cpp
Chest::Chest(int armor, std::string name) : Armor(armor, name) {
	this->id = 4;
}

Chest::Chest(int armor, std::string name, int value) : Armor(armor, name, value) {
	this->id = 4;
}
//legs.cpp
Legs::Legs(int armor, std::string name) : Armor(armor, name) {
	this->id = 5;
}
Legs::Legs(int armor, std::string name, int value) : Armor(armor, name, value) {
	this->id = 5;
}
