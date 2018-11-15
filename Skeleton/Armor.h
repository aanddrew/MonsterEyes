#ifndef ARMOR_H
#define ARMOR_H

#include "Equipable.h"

#include <string>

using namespace std;

class Armor : public Equipable
{
private:
	float extraHealth;
	int slot;
public:
	Armor(string, float, int);

	float getExtraHealth();
	int getSlot();

	void equip();
	void unequip();

};
#endif