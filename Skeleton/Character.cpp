#include "Character.h"

Character::Character(float healthIn, float maxHealthIn)
{
	health = healthIn;
	maxHealth = maxHealthIn;

	inventory.reserve(20);
	for (int i = 0; i < inventory.capacity(); i++)
	{
		Item h(to_string(i) + " a");
		inventory.push_back(h);
	}
}

float Character::getHealth()
{
	return health;
}
float Character::getMaxHealth()
{
	return maxHealth;
}

//setters
//returns true if the player is still alive after changing health
bool Character::setHealth(float healthIn)
{
	health = healthIn;
}
//permanently change the players maxHealth
void Character::setMaxHealth(float healthIn)
{
	maxHealth = healthIn;
}

float Character::getDamageDealt()
{
	return 1.0;
}

//more getters/setters
int Character::getInventorySize()
{
	return inventory.capacity();
}
Item Character::getItemAt(int i)
{
	return inventory.at(i);
}
// Equipable Character::getWearingAt(int i);
