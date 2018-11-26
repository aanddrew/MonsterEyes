#include "Weapon.h"

using namespace std;

Weapon::Weapon(string nameIn, int maxDamageIn) : Equipable(nameIn, 0)
{
	maxDamage = maxDamageIn;
}


int Weapon::getMaxDamage()
{
	return maxDamage;
}

bool Weapon::equip(Character *c)
{
	c->getWearing()[0] = this;
	c->setMaxDamage(this->getMaxDamage());
}
bool Weapon::unequip(Character *c)
{
	c->getWearing()[0] = NULL;
	c->setMaxDamage(1);
}

string Weapon::getInfo()
{
	string returned = name;
	returned += " does a maximum of ";
	returned += to_string(maxDamage);
	returned += " damage.";
	return returned;
}