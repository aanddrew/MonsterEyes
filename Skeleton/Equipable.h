#ifndef EQUIPABLE_H
#define EQUIPABLE_H

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

public:
	Equipable(string);

	//these eventually to take player as an argument
	virtual void equip()=0;
	virtual void unequip()=0;
};

#endif