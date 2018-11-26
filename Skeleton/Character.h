#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstdlib>
#include <string>
#include <vector>

#include "Item.h"
#include "Equipable.h"
// #include "Weapon.h"
// #include "Armor.h"

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

	int maxDamage;

	vector<Item*> inventory;
	Equipable* wearing[5];

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

	void setMaxDamage(int);
	int getMaxDamage();

	//more getters/setters
	int getInventorySize();
	vector<Item*>* getInventory();
	Equipable** getWearing();
};

#endif