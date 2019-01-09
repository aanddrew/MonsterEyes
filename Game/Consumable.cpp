#include "Consumable.h"

using namespace std;

/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

Consumable::Consumable(string nameIn) : Item(nameIn)
{
}

string Consumable::getInteraction()
{
	return "consume";
}

void Consumable::interact(Character* c)
{
	this->consume(c);
}