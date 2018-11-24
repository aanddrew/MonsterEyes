#include "Weapon.h"

using namespace std;

Weapon::Weapon(string nameIn, int maxDamageIn) : Equipable(nameIn)
{
	maxDamage = maxDamageIn;
}


int Weapon::getMaxDamage()
{
	return maxDamage;
}

int Weapon::getDamage()
{
	int d = rand() % getMaxDamage() + 1;
	return d;
}

bool Weapon::equip(Character *c)
{
	return true;
}
bool Weapon::unequip(Character *c)
{
	return true;
}