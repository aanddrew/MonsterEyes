/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#ifndef EQUIPABLE_H
#define EQUIPABLE_H

class Character;

#include "Item.h"

#include <string>

using namespace std;

/*
Equipables are Items that can be equiped. I.E. they have an equip function
This is an abstract class that will be inherited by Armor and Weapon.
*/
class Equipable : public Item
{
private:
	int slot;
public:
	Equipable(string, int);

	int getSlot();

	//these eventually to take player as an argument
	virtual bool equip(Character*)=0;
	virtual bool unequip(Character*)=0;

	string getInteraction();
	void interact(Character*c);

	// virtual string getInfo()=0;
};

#endif