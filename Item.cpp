#include "Item.h"

void Item::initialize()
{
	this->name_ = new std::string();

	this->current_durability = new unsigned int();
	this->max_durability     = new unsigned int();
	this->cost_              = new unsigned int();

	this->isPiercesSpellImmunity_ = new bool();
	this->canBeDropped_           = new bool();
	this->isDestroyed_            = new bool();
	this->isDropped_              = new bool();

	this->owner_ = new Hero();
	this->holder_ = new Hero();
}

Item::Item(unsigned int cost, std::string item_name)
{
	this->initialize();

	*this->cost_ = cost;
	*this->name_ = item_name;

	*this->max_durability = 100;
	*this->current_durability = *this->max_durability;
}

bool Item::isPiercesSpellImmunity()
{
	return *this->isPiercesSpellImmunity_;
}

bool Item::canBeDropped()
{
	return *this->canBeDropped_;
}

bool Item::isDropped()
{
	return *this->isDropped_;
}

bool Item::canBeUsed()
{
	return *this->current_durability > 0;
}

void Item::drop()
{
	*this->isDropped_ = true;
}

void Item::destroy()
{
	*this->current_durability = 0;
}

void Item::setCost(unsigned int value)
{
}

unsigned int Item::getCost()
{
	return 0;
}
