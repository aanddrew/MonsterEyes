/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

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