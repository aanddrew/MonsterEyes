#ifndef WEAPON_H
#define WEAPON_H

// class Character;

#include "Equipable.h"
#include "Player.h"
#include "Character.h"

#include <cstdlib>
#include <string>

using namespace std;


class Weapon : public Equipable
{
private:
	int maxDamage;
public:
	Weapon(string, int);

	int getMaxDamage();

	bool equip(Character*);
	bool unequip(Character*);

	string getInfo();
};
#endif