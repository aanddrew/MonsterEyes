#include <iostream>

#include "Equipable.h"

using namespace std;


//This class is basically a dummy class to have Items that can be equiped.
Equipable::Equipable(string nameIn, int slotIn) : Item(nameIn)
{
	slot = slotIn;
}

int Equipable::getSlot(){return slot;}