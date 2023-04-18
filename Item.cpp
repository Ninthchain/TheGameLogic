#include "Item.h"

void Item::initialize()
{
	this->name_ = new std::string();

	this->current_durability = new unsigned int(100);
	this->max_durability     = new unsigned int(100);
	this->cost_              = new unsigned int(0);

	this->isPiercesSpellImmunity_ = new bool(false);
	this->canBeDropped_           = new bool(true);
	this->isDestroyed_            = new bool(false);
	this->isDropped_              = new bool(false);

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

Item::~Item()
{
	delete this->cost_;
	delete this->canBeDropped_;
	delete this->current_durability;
	delete this->name_;
	delete this->max_durability;
	delete this->owner_;
	delete this->holder_;
	delete this->isDestroyed_;
	delete this->isDropped_;
	delete this->isPiercesSpellImmunity_;
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
	this->holder_ = nullptr;
	*this->isDropped_ = true;
}

void Item::destroy()
{
	*this->current_durability = 0;
}

void Item::setOwner(Hero new_owner)
{
	*this->owner_ = new_owner;
}

void Item::setHolder(Hero new_holder)
{
	*this->holder_ = new_holder;
}

void Item::setCost(unsigned int value)
{
	*this->cost_ = value;
}

unsigned int Item::getId()
{
	return *this->id_;
}

unsigned int Item::getCost()
{
	return *this->cost_;
}
