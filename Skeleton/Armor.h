#ifndef ARMOR_H
#define ARMOR_H

#include "Equipable.h"
#include "Player.h"
#include "Character.h"

#include <string>

using namespace std;


/*
Armor is an item that can be equiped onto a player.
When equiped, it gives the player extraHealth
When unequiped, it subracts extraHealth from the player
*/
class Armor : public Equipable
{
private:
	float extraHealth;
	int slot;
public:
	Armor(string, float, int);

	float getExtraHealth();
	int getSlot();

	bool equip(Character*);
	bool unequip(Character*);

};
#endif