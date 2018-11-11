#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Item.h"
#include "Equipable.h"

class Player : public Character
{
private:
	Zone zone;
public:
	Player();

	void showSelfInteractions();
	void displayInventory();
};

#endif