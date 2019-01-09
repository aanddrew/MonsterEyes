/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#include "HealthPot.h"

#include "Consumable.h"

using namespace std;

HealthPot::HealthPot(string nameIn, int healthIn) : Consumable(nameIn)
{
	health = healthIn;
}

bool HealthPot::consume(Character* c)
{
	//if the player would be healed past full health, set their health to full
	if (c->getHealth()+health > c->getMaxHealth())
	{
		c->setHealth(c->getMaxHealth());
	}
	//otherwise just add the health from the pot
	else
	{
		c->setHealth(c->getHealth() + health);
	}

	for (int i = 0; i < c->getInventory()->size(); i++)
	{
		if (c->getInventory()->at(i) == this)
		{
			c->getInventory()->erase(c->getInventory()->begin()+i);
		}
	}
}

int HealthPot::getHealth()
{
	return health;
}

string HealthPot::getInfo()
{
	return this->getName() + " restores " + to_string(health) + " health to you.";
}