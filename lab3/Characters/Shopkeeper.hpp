#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "../Items/Item.hpp"


#ifndef SHOPKEEPER_HPP
#define SHOPKEEPER_HPP
class Shopkeeper {
private:
	std::vector<Item*> inventory;
public:
	Shopkeeper(std::vector<Item*> inventory);
<<<<<<< HEAD
	void displayInventory();
	std::vector<Item*> getinv() const;
=======
	~Shopkeeper();
	void displayInventory();
	std::vector<Item*> getinv() const;
	void setinv(std::vector<Item*>);
>>>>>>> dbe35af8e2e46d410ef68af57df2f8226b405965
};

#endif