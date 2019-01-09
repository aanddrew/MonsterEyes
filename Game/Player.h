/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

// class Character;

#include "Character.h"

using namespace std;

class Player : public Character
{
private:
	
public:
	Player();
	Player(string);

	void levelUp();

	void showSelfInteractions();
	void showInventory();
	void showInfo();
};

#endif