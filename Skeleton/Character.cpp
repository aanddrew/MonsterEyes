#include "Character.h"

Character::Character()
{
	name = "NULL";
	health = 0;
	maxHealth = 0;
	level = 0;
	xp = 0;
}
/*
Character is a class that will be used to represent:
The player
The enemies.
NPCs
*/
Character::Character(string nameIn, float maxHealthIn)
{
	name = nameIn;
	health = maxHealthIn;
	maxHealth = maxHealthIn;


	for (int i = 0; i < 20; i++)
	{
		Item h(to_string(i) + " a");
		inventory[i] = &h;
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
string Character::getName()
{
	return name;
}

//setters
//returns true if the player is still alive after changing health
void Character::setHealth(float healthIn)
{
	health = healthIn;
}
//permanently change the players maxHealth
void Character::setMaxHealth(float healthIn)
{
	maxHealth = healthIn;
}

void Character::setLevel(int levelIn)
{
	level = levelIn;
}
int Character::getLevel()
{
	return level;
}

void Character::levelUp()
{
	level++;
	maxHealth += 6;
	health = maxHealth;
}

int Character::getDamageDealt()
{
	// if (w == NULL)
	// {
	// 	return 1;
	// }
	// else
	// {
	// 	return w->getDamage();
	// }
}

//more getters/setters
int Character::getInventorySize()
{
	return 20;
}
Item* Character::getItemAt(int i)
{
	return inventory[i];
}
// Equipable Character::getWearingAt(int i);
