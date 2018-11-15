#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
protected:
	string name;
public:
	Item(string);
	void setName(string);
	string getName();
};
#endif