#include <iostream>

#include "Item.h"
#include "Character.h"

using namespace std;


Item::Item(string nameIn)
{
	name = nameIn;
}

void Item::setName(string nameIn)
{
	name = nameIn;
}

string Item::getName()
{
	return name;	
}

string Item::getInfo()
{
	return "Hello";
}

string Item::getInteraction()
{
	return "n/a";
}

void Item::interact(Character* c)
{

}