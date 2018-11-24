#ifndef FIGHT_H
#define FIGHT_H

#include "Room.h"
#include "Character.h"

#include <iostream>
#include <string>

using namespace std;

class Fight : Public Room
{
private:

public:
	Room(string, string, string, Character, int);

	void showInteractions();
	//returns the refernce returne from this interaction
	//It may return the index of a dungeon or a boolean if the monster in it is dead
	int doInteraction(int);
};

#endif