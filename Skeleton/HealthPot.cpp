#include "HealthPot.h"

#include "Consumable.h"

using namespace std;

HealthPot::HealthPot(int healthIn) : Consumable("Health Potion")
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

string HealthPot::getInfo()
{
	return "Health Potion heals restores " + to_string(health) + " health to you.";
}