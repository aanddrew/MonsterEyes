#include <iostream>

#include "Item.h"

using namespace std;

Item::Item(string nameIn)
{
	name = nameIn;
}

string Item::getName()
{
	return name;	
}