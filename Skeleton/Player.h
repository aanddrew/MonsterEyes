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

	void showSelfInteractions();
	void displayInventory();
};

#endif