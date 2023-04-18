#include "Inventory.h"

Inventory::Inventory(unsigned int max_size)
{
	*this->current_size = 0;
	*this->max_size = max_size;
}

Inventory::~Inventory()
{
	for (auto it = this->items->begin(); it != this->items->end(); ++it)
		delete* it;
	delete this->items;
	delete this->max_size;
	delete this->current_size;
}

void Inventory::resize(unsigned int new_size)
{
}

void Inventory::addItem(Item* itemPtr)
{
	if (this->isFull())
		throw new std::exception("The inventory is full");

	this->items->push_back(itemPtr);
	++(*this->current_size);
}

void Inventory::removeItemById(unsigned int id, bool all)
{
}

void Inventory::removeItemByName(std::string name, bool all)
{
}

void Inventory::setItem(unsigned int id, Item value)
{
	for (auto elem : *items)
	{
		if (elem->getId() == id)
		{
			*elem = value;
			return;
		}
	}
}

bool Inventory::isEmpty()
{
	return false;
}

bool Inventory::isFull()
{
	return false;
}

Item Inventory::getItemById(unsigned int id)
{
	for (auto elem : *items)
	{
		if (elem->getId() == id)
			return *elem;
	}
	throw new std::exception("ItemNotFound");
}

Item* Inventory::getItemPtrById(unsigned int id)
{
	for (auto elem : *items)
	{
		if (elem->getId() == id)
			return elem;
	}
	throw new std::exception("ItemNotFound");
}
