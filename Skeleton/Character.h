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
	int health;
	int maxHealth;

	int gold;

	int maxDamage;

	vector<Item*> inventory;
	Equipable* wearing[5];
	bool wearingFlags[5] ={false,false,false,false,false};

	// Weapon* w;

	int level;

	int xp;

public:
	Character();
	Character(string, int);
	//getters
	int getHealth();
	int getMaxHealth();

	void setName(string);
	string getName();

	//setters
	//returns true if the player is still alive after changing health
	void setHealth(int);
	//permanently change the players maxHealth
	void setMaxHealth(int);

	void setGold(int);
	int getGold();

	void setLevel(int);
	int getLevel();

	void setXP(int);
	int getXP();

	void levelUp();

	int getDamageDealt();

	void setMaxDamage(int);
	int getMaxDamage();

	//more getters/setters
	int getInventorySize();
	vector<Item*>* getInventory();
	Equipable** getWearing();
	void setWearing(int, bool);
	bool isWearing(int);

	bool alive();
};

#endif