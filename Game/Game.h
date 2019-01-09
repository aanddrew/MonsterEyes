/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include <fstream>

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
	const int numZones;
	Zone zones[10];

	int currentZone;
	int currentRoom;
	int currentDungeon;
public:
	Game();

	void loadGame();

	void generateZones();

	void changeZone(int);

	void enterRoom();
	void enterDungeon();

	void testGame();
	void testGame2();
	void testGame3();
	void testGame4();

	void showPlayerOptions();
	bool getPlayerOptions(string);

	void showSaveOptions();
	bool getSaveOptions(string input);

	void playGame();

	void saveGame();
};
#endif