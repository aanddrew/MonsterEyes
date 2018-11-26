#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;
/*
This class represents an Item, which is any item that can be stored in the player's inventory
The player will have an array of items which will represent their inventory.
*/
class Item
{
protected:
	string name;
public:
	Item(string);
	void setName(string);
	string getName();

	virtual string getInfo();
};
#endif