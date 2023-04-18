#pragma once
#include <vector>
#include "Item.h"

class Inventory
{
private:
	std::vector<Item*>* items;
	unsigned int *max_size;

	void initialize();

public:
	Inventory(unsigned int max_size);
	~Inventory();

	void resize(unsigned int new_size);

	void addItem(Item* itemPtr);

	void dropItemById(unsigned int id, bool all);
	void dropItemByIndex(unsigned int index, bool all);

	void setItem(unsigned int id, Item value);

	bool isEmpty();
	bool isFull();

	Item getItemById(unsigned int id);
	Item* getItemPtrById(unsigned int id);
};

