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