#ifndef DUNGEON_H
#define DUNGEON_H

#include "Player.h"
#include "Room.h"

class Dungeon
{
private:
	int currentRoom;
	vector<Room> rooms;
public:
	void showInteractions();
	bool doInteraction(Player, int);
};

#endif