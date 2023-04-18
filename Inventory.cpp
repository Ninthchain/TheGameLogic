#include "Inventory.h"

void Inventory::initialize()
{
	this->items = new std::vector<Item*>;
}

Inventory::Inventory(unsigned int max_size)
{
	this->initialize();

	this->items = new std::vector<Item*>(max_size); 
	*this->max_size = max_size;
}

Inventory::~Inventory()
{
	for (auto it = this->items->begin(); it != this->items->end(); ++it)
		delete* it;

	delete this->items;
	delete this->max_size;
}

void Inventory::resize(unsigned int new_size)
{
	*this->max_size = new_size;
}

void Inventory::addItem(Item* itemPtr)
{
	if (this->isFull())
		throw new std::exception("The inventory is full");

	this->items->push_back(itemPtr);
}

void Inventory::dropItemById(unsigned int id, bool all)
{
	for (auto it = this->items->begin(); it != this->items->end(); ++it)
	{
		if ((*it)->getId() == id)
		{
			(*it)->drop();
			this->items->erase(it);
			
			return;
		}
	}
	throw new std::exception("ItemNotFoundException");
}
void Inventory::dropItemByIndex(unsigned int index, bool all)
{
	auto elem = this->items->begin() + index;
	(*elem)->drop();
	this->items->erase(elem);
}

void Inventory::setItem(unsigned int id, Item value)
{
	for (auto elem : *this->items)
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
	return this->items->empty();
}

bool Inventory::isFull()
{
	return this->items->size() == *this->max_size;
}

Item Inventory::getItemById(unsigned int id)
{
	for (auto elem : *this->items)
	{
		if (elem->getId() == id)
			return *elem;
	}
	throw new std::exception("ItemNotFound");
}

Item* Inventory::getItemPtrById(unsigned int id)
{
	for (auto elem : *this->items)
	{
		if (elem->getId() == id)
			return elem;
	}
	throw new std::exception("ItemNotFound");
}
