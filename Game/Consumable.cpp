#include "Consumable.h"

using namespace std;

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