#include "Weapon.h"

using namespace std;

Weapon::Weapon(string nameIn, int maxDamageIn) : Equipable(nameIn, 0)
{
	maxDamage = maxDamageIn;
}


int Weapon::getMaxDamage()
{
	return maxDamage;
}

bool Weapon::equip(Character *c)
{
	//If the player is already wearing something
	if (c->isWearing(0))
	{
		//put it into their inventory
		c->getInventory()->push_back(c->getWearing()[0]);
	}
	//they are now wearing something
	c->setWearing(0,true);
	//they are waering this
	c->getWearing()[0] = this;

	//erase the item from their inventory now
	for (int i = 0; i < c->getInventory()->size(); i++)
	{
		if (c->getInventory()->at(i) == this)
		{
			c->getInventory()->erase(c->getInventory()->begin()+i);
			break;
		}
	}

	//the effects of equiping
	c->setMaxDamage(this->getMaxDamage());
}
bool Weapon::unequip(Character *c)
{
	//they are no longer wearing anything
	c->setWearing(0,false);
	//put the item they were wearing in their inventory
	c->getInventory()->push_back(this);
	//I dont know if this does anything
	c->getWearing()[0] = NULL;

	//back to 1 dmg attacks
	c->setMaxDamage(1);
}
string Weapon::getInfo()
{
	return name + " does a maximum of " + to_string(maxDamage) + " damage.";
}