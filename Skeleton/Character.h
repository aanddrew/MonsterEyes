#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>

#include "Item.h"
// #include "Equipable.h"

using namespace std;

class Character
{
private:
	float health;
	float maxHealth;
	vector<Item> inventory;
	// Equipable wearing[];

public:
	Character(float,float);
	//getters
	float getHealth();
	float getMaxHealth();

	//setters
	//returns true if the player is still alive after changing health
	bool setHealth(float);
	//permanently change the players maxHealth
	void setMaxHealth(float);

	float getDamageDealt();

	//more getters/setters
	int getInventorySize();
	Item getItemAt(int);
	// Equipable getWearingAt(int);
};

#endif