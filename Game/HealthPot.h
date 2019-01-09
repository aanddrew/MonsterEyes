/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

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
	HealthPot(string, int);

	bool consume(Character*);

	int getHealth();

	string getInfo() override;
};


#endif