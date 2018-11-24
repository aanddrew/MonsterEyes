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

	int level;

	vector<Room> rooms;
	vector<Dungeon> dungeons;

	int currentRoom;
	int currentDungeon;
public:
	//for testing purposes
	Zone();
	//not for testing
	Zone(int);

	void showInteractions();
	void interact();

	void enterDungeon(int);

	int getLevel();
	Room getRoomAt(int);
};

#endif