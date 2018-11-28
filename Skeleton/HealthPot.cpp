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
	c->setHealth(c->getHealth() + health);
}

int HealthPot::getHealth()
{
	return health;
}

string HealthPot::getInfo()
{
	return "Health Potion heals restores " + to_string(health) + " health to you.";
}