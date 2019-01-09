#ifndef CONSUMABLE_H
#define CONSUMABLE_H

class Character;

#include "Item.h"

#include <string>

using namespace std;

/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

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
	string getInteraction();
	void interact(Character*);
};

#endif