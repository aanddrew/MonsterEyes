#ifndef ARMOR_H
#define ARMOR_H

#include "Equipable.h"
#include "Character.h"

#include <string>

using namespace std;

/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/


/*
Armor is an item that can be equiped onto a player.
When equiped, it gives the player extraHealth
When unequiped, it subracts extraHealth from the player
*/
class Armor : public Equipable
{
private:
	int extraHealth;
public:
	Armor(string, int, int);

	int getExtraHealth();

	bool equip(Character*);
	bool unequip(Character*);

	string getInfo() override;
};
#endif