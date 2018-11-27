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

	void enterDungeon(int);

	int getLevel();
};
#endif