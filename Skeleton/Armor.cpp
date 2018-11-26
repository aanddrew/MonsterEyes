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
	c->setMaxHealth(c->getMaxHealth() + extraHealth);
	return true;
}

bool Armor::unequip(Character *c)
{
	c->setMaxHealth(c->getMaxHealth() - extraHealth);
	return true;
}

string Armor::getInfo()
{
	return name + " gives you " + to_string(extraHealth) + " extra health.";
}