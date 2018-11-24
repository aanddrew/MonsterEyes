#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

#include "Item.h"
// #include "Equipable.h"
// #include "Weapon.h"

using namespace std;

/*
Characters represent characters in the game i.e:
The player
NPCS
Enemys

They have health and a level and xp.
*/
class Character
{
private:
	string name;
	float health;
	float maxHealth;

	Item* inventory[20];
	// Equipable* wearing[4];

	// Weapon* w;

	int level;

	int xp;

public:
	Character();
	Character(string, float);
	//getters
	float getHealth();
	float getMaxHealth();
	string getName();

	//setters
	//returns true if the player is still alive after changing health
	void setHealth(float);
	//permanently change the players maxHealth
	void setMaxHealth(float);

	void setLevel(int);
	int getLevel();

	void levelUp();

	int getDamageDealt();

	//more getters/setters
	int getInventorySize();
	Item* getItemAt(int);
	// Equipable getWearingAt(int);
};

#endif