#include "Shopkeeper.hpp"

Shopkeeper::Shopkeeper(std::vector<Item*> inv) {
	this->inventory = inv;
}

Shopkeeper::~Shopkeeper() {
	for (auto it = inventory.begin(); it != inventory.end(); ++it)
	{
		delete *it;
	}
}

void Shopkeeper::displayInventory() {
	for(int i = 0; i < this->inventory.size(); i++) {
		std::cout << i << ": " << this->inventory.at(i)->desc() << "value: " << this->inventory.at(i)->getvalue() << "\n";
	}
	std::cout << this->inventory.size() << ": to enter sell mode \n";
}


std::vector<Item*> Shopkeeper::getinv() const {
	return this->inventory;
}
void Shopkeeper::setinv(std::vector<Item*> newinv) {
	this->inventory = newinv;
}