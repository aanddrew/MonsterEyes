#ifndef GAME_H
#define GAME_H

#include <string>

#include "Player.h"
#include "Zone.h"
#include "Dungeon.h"
#include "Room.h"
#include "Item.h"
#include "Weapon.h"
#include "Consumable.h"
#include "HealthPot.h"

using namespace std;

class Game
{
private:
	Player p;
	Zone zones[10];

	int currentZone;
	int currentRoom;
	int currentDungeon;
public:
	Game();

	void generateZones();

	void changeZone(int);

	void enterRoom();
	void enterDungeon();

	void testGame();
	void testGame2();
};
#endif