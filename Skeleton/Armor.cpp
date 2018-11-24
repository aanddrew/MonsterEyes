#include "Armor.h"

#include <iostream>
#include <string>

using namespace std;

/*
Armor is an equipable* item* that does one thing
On equip, it gives the player extra health.
On unequip, it removes that extra health from the player.
Simple.
*/
Armor::Armor(string nameIn, float extraHealthIn, int slotIn) : Equipable(nameIn)
{
	extraHealth = extraHealthIn;
	slot = slotIn;

}

float Armor::getExtraHealth()
{
	return extraHealth;
}

int Armor::getSlot()
{
	return slot;
}



bool Armor::equip(Character *c)
{
	// Item* i = this;
	// cout << "my name is: " << i->getName() << endl;

	// cout << "my name is: " << this->getName() << endl;

	c->setMaxHealth(c->getMaxHealth() + extraHealth);
	return true;
}

bool Armor::unequip(Character *c)
{
	c->setMaxHealth(c->getMaxHealth() - extraHealth);
	return true;
}