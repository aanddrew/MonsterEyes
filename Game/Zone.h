/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#ifndef ZONE_H
#define ZONE_H

#include <string>
#include <vector>

#include "Player.h"
#include "Room.h"
#include "Dungeon.h"

class Zone
{
private:
	string name;

	int numRooms;
	int numDungeons;
	int level;

	vector<Room*> rooms;
	vector<Dungeon*> dungeons;

	Room* foodShop;
	Room* itemShop;

	int currentRoom;
	int currentDungeon;
public:
	//for testing purposes
	Zone();
	//not for testing
	Zone(int, int, int);

	void showInteractions();
	void interact();

	int getNumRooms();
	int getNumDungeons();

	vector<Dungeon*>* getDungeons();
	vector<Room*>* getRooms();

	Room* getFoodShop();
	Room* getItemShop();

	void enterDungeon(int);

	int getLevel();
};
#endif