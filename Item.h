#pragma once
#include <string>
#include "./Hero.h"


class Item
{
private:
	Hero* owner_;
	Hero* holder_;

	unsigned int* id_;
	unsigned int* cost_;
	unsigned int* current_durability;
	unsigned int* max_durability;

	std::string* name_;

	bool* isPiercesSpellImmunity_;
	bool* isDropped_;
	bool* isDestroyed_;
	bool* canBeDropped_;

	void initialize();

public:
	Item(unsigned int cost, std::string item_name);
	~Item();


	bool isPiercesSpellImmunity();
	bool canBeDropped();
	bool isDropped();
	bool canBeUsed();

	void drop();
	void destroy();

	void setOwner(Hero new_owner);
	void setHolder(Hero new_holder);
	void setCost(unsigned int value);
	
	unsigned int getId();
	unsigned int getCost();
};

