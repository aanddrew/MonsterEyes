#include "Zone.h"

using namespace std;

Zone::Zone()
{
	level = 1;
}

Zone::Zone(int levelIn, int numRoomsIn, int numDungeonsIn)
{
	numRooms = numRoomsIn;
	numDungeons = numDungeonsIn;
	level = levelIn;
	dungeons.reserve(numDungeons);
}

vector<Dungeon*>* Zone::getDungeons()
{
	return &dungeons;
}

vector<Room*>* Zone::getRooms()
{
	return &rooms;
}

int Zone::getNumRooms()
{
	return numRooms; 
}

int Zone::getNumDungeons()
{
	return numDungeons;
}

// void showInteractions();
// void interact();

// void enterDungeon(int);

int Zone::getLevel()
{
	return level;
}