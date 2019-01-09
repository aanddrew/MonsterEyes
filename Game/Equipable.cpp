/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#include <iostream>

#include "Equipable.h"

using namespace std;


//This class is basically a dummy class to have Items that can be equiped.
Equipable::Equipable(string nameIn, int slotIn) : Item(nameIn)
{
	slot = slotIn;
}

int Equipable::getSlot(){return slot;}

string Equipable::getInteraction()
{
	return "equip";
}

void Equipable::interact(Character* c)
{
	this->equip(c);
}