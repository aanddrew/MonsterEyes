#ifndef EQUIPABLE_H
#define EQUIPABLE_H

#include "Item.h"

#include <string>

class Equipable : public Item
{
private:

public:
	Equipable(string);

	virtual void equip(Player) = 0;
	virtual void unequip(Player) = 0;
};

#endif