#include "Item.hpp"
<<<<<<< HEAD
//item.cpp
=======
//item.cpp ===============================================
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
const std::string Item::desc() const {
	std::string ret = "this is an item \n";
	return ret;
}
void Item::setValue(int value) {
	this->value = value;
}
const int Item::getvalue() const {
	return this->value;
}
const int Item::getid() const {
	return this->id;
}
<<<<<<< HEAD
//potion.cpp
=======

//potion.cpp ===============================================
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
Potion::Potion(int heal, std::string name) {
	this->heal = heal;
	this->name = name;
	this->id = 6;
}
Potion::Potion(int heal, std::string name, int value) {
	this->heal = heal;
	this->name = name;
	this->id = 6;
	this->value = value;
}
const std::string Potion::desc() const {
	std::string ret = "Potion: " + name + " ";
	return ret;
}
const int Potion::getheal() const {
	return this->heal;
}
<<<<<<< HEAD
//weapon.cpp
=======
//weapon.cpp ===============================================
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
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
const std::string Weapon::desc() const {
	std::string ret = "weapon: " + name + " ";
	return ret;
}
<<<<<<< HEAD
//armor.cpp
=======

const int Weapon::spec() const {
	std::cout << "Stop hitting urself ( - 10 HP) ";
	return 1;
}

//KnightsSword.cpp ===============================================

const int KnightsSword::spec() const {
	std::cout << "Next thing you know you are being dubbed by the king in his own castle" << std::endl;
	return 2;
}

KnightsSword::KnightsSword(int dmg, std::string name, int value) : Weapon(dmg, name, value){
}

const std::string KnightsSword::desc() const {
	std::string ret = "A knight's sword ";
	return ret;
}

//DragonTooth.cpp ===============================================

const int DragonTooth::spec() const {
	std::cout << "You can feel your blood starting to bubble and after a while you realise that you just grew a pair of wings" << std::endl;
	std::cout << "You wake up next to a burned house, maybe you did this?" << std::endl;
	return 3;
}

DragonTooth::DragonTooth(int dmg, std::string name, int value) : Weapon(dmg, name, value){
}

const std::string DragonTooth::desc() const {
	std::string ret = "A dragon's Tooth ";
	return ret;
}

//GodSword.cpp ===============================================

const int GodSword::spec() const {
	std::cout << "Since you are a god now we cannot stop you from finishing the game" << std::endl;
	return 4;
}

GodSword::GodSword(int dmg, std::string name, int value) : Weapon(dmg, name, value){
}

const std::string GodSword::desc() const {
	std::string ret = "lolnoobs";
	return ret;
}

//armor.cpp ===============================================

>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
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
const int Armor::getarmor() const {
	return this->armor;
}

const std::string Armor::desc() const {
	std::string ret = "armor: " + name + " ";
	return ret;
}

<<<<<<< HEAD
//helm.cpp
=======
//helm.cpp ===============================================
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
Helm::Helm(int armor, std::string name) : Armor(armor, name) {
	this->id = 3;
}
Helm::Helm(int armor, std::string name, int value) : Armor(armor, name, value) {
	this->id = 3;
}
<<<<<<< HEAD
//chest.cpp
=======
//chest.cpp ===============================================
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
Chest::Chest(int armor, std::string name) : Armor(armor, name) {
	this->id = 4;
}

Chest::Chest(int armor, std::string name, int value) : Armor(armor, name, value) {
	this->id = 4;
}
<<<<<<< HEAD
//legs.cpp
=======
//legs.cpp ===============================================
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
Legs::Legs(int armor, std::string name) : Armor(armor, name) {
	this->id = 5;
}
Legs::Legs(int armor, std::string name, int value) : Armor(armor, name, value) {
	this->id = 5;
}
