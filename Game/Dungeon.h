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