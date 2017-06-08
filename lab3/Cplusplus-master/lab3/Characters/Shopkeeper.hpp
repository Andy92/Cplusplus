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
	~Shopkeeper();
	void displayInventory();
	std::vector<Item*> getinv() const;
	void setinv(std::vector<Item*>);
};

#endif