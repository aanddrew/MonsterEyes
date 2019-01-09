/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#ifndef DUNGEON_H
#define DUNGEON_H

#include <cstdlib>
#include "Player.h"
#include "Room.h"

#include <string>

class Dungeon
{
private:
	int currentRoom;
	vector<Room*> rooms;
public:
	Dungeon(string, int, int, int);

	string getMonsterName();

	vector<Room*>* getRooms();
};

#endif