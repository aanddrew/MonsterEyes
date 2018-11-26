#ifndef HEALTHPOT_H
#define HEALTHPOT_H

#include "Consumable.h"
#include "Character.h"

#include <string>

using namespace std;

class HealthPot : public Consumable
{
private:
	int health;
public:
	HealthPot(int);

	bool consume(Character*);

	string getInfo() override;
};


#endif