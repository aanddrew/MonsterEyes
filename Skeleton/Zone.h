#ifndef ZONE_H
#define ZONE_H

#include <string>

#include "Player.h"
#include "Room.h"

class Zone
{
private:
	string name;

	vector<Room> rooms;
	vector<Dungeon> dungeons;

	int currentRoom;
public:
	void showInteractions();
	void interact();

	void enterDungeon(int);

	Room getRoomAt(int);
};

#endif