#include "Shopkeeper.hpp"

Shopkeeper::Shopkeeper(std::vector<Item*> inv) {
	this->inventory = inv;
}

<<<<<<< HEAD
=======
Shopkeeper::~Shopkeeper() {
	for (auto it = inventory.begin(); it != inventory.end(); ++it)
	{
		delete *it;
	}
}

>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
void Shopkeeper::displayInventory() {
	for(int i = 0; i < this->inventory.size(); i++) {
		std::cout << i << ": " << this->inventory.at(i)->desc() << "value: " << this->inventory.at(i)->getvalue() << "\n";
	}
	std::cout << this->inventory.size() << ": to enter sell mode \n";
}


std::vector<Item*> Shopkeeper::getinv() const {
	return this->inventory;
<<<<<<< HEAD
=======
}
void Shopkeeper::setinv(std::vector<Item*> newinv) {
	this->inventory = newinv;
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
}