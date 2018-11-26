#ifndef CONSUMABLE_H
#define CONSUMABLE_H

class Character;

#include "Item.h"

#include <string>

using namespace std;

/*
Consumables are objects that can be consumed to give the player extra health;
.Consume heals the player
*/
class Consumable : public Item
{
private:
public:
	Consumable(string);

	virtual bool consume(Character*)=0;
};

#endif