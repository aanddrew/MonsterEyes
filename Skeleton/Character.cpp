#include <iostream>

#include "Character.h"

using namespace std;

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

	level = 0;
	xp = 0;


	inventory.reserve(20);
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
	if (wearing[0] == NULL)
	{
		return 1;
	}
	else
	{
		return rand() % getMaxDamage() + 1;
	}
}

void Character::setMaxDamage(int dmgIn)
{
	maxDamage = dmgIn;
}
int Character::getMaxDamage(){return maxDamage;}


//more getters/setters

vector<Item*>* Character::getInventory()
{
	return &inventory;
}
Equipable** Character::getWearing()
{
	return wearing;
}