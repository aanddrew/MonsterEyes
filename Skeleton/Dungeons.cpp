#include "Dungeon.h"

using namespace std;

/*
Dungeons contains rooms which contain Characters
These characters are intended to be 
*/
Dungeon::Dungeon(string nameIn, int numRooms, int maxDamage, int levelIn)
{
	currentRoom = 0;

	rooms.reserve(numRooms);

	int health = levelIn * 2 + rand() % (levelIn+1);
	for (int i = 0; i < numRooms; i++)
	{
		Character * enemy = new Character(nameIn, health);
		enemy->setMaxDamage(maxDamage);
		enemy->setLevel(levelIn);
		enemy->setXP(maxDamage*10 + rand()%(levelIn*10));
		enemy->setWearing(0, true);

		Room *r = new Room(enemy, "","", i+1);
		rooms.push_back(r);
	}
}

vector<Room*>* Dungeon::getRooms()
{
	return &rooms;
}

string Dungeon::getMonsterName()
{
	return rooms.at(0)->getCharacter()->getName();
}
