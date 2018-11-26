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

	// virtual string getInfo()=0;
};

#endif