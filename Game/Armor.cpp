#include "Armor.h"

#include <iostream>
#include <string>

using namespace std;

/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

/*
Armor is an equipable* item* that does one thing
On equip, it gives the player extra health.
On unequip, it removes that extra health from the player.
Simple.
*/
Armor::Armor(string nameIn, int extraHealthIn, int slotIn) : Equipable(nameIn, slotIn)
{
	extraHealth = extraHealthIn;
}

int Armor::getExtraHealth()
{
	return extraHealth;
}

bool Armor::equip(Character *c)
{
	//if the player is already wearing something
	if (c->isWearing(this->getSlot()))
	{
		//put it back in their inventory
		c->getInventory()->push_back(c->getWearing()[this->getSlot()]);
	}

	//the player is now wearing something in this slot
	c->setWearing(this->getSlot(), true);

	//the player is wearing /this/ in the slot
	// cout << this->getName() << endl;
	c->getWearing()[this->getSlot()] = this;

	cout << c->isWearing(this->getSlot()) << endl;
	cout << c->getWearing()[this->getSlot()]->getName() << endl;
	cout << c->getWearing()[this->getSlot()]->getName() << endl;
	//erase the item from their inventory now.
	for (int i = 0; i < c->getInventory()->size(); i++)
	{
		if (c->getInventory()->at(i) == this)
		{
			c->getInventory()->erase(c->getInventory()->begin()+i);
			break;
		}
	}

	//apply the effects of equiping
	c->setMaxHealth(c->getMaxHealth() + extraHealth);
	return true;
}

bool Armor::unequip(Character *c)
{
	//this player no longer wears something in this slot
	c->setWearing(this->getSlot(), false);

	//put it back in their inventory
	c->getInventory()->push_back(this);
	//remove effects of equiping this object
	c->setMaxHealth(c->getMaxHealth() - extraHealth);

	c->getWearing()[this->getSlot()] = NULL;
	return true;
}

string Armor::getInfo()
{
	return name + " gives you " + to_string(extraHealth) + " extra health.";
}