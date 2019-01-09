/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#ifndef ROOM_H
#define ROOM_H

#include "Character.h"

#include <iostream>
#include <string>

using namespace std;

class Room
{
private:
	Character* c;

	string building;
	string message;

	//either tells you which dungeon to go to or which room is next inside the dungeon
	int ref;

public:
	Room(Character*, string, string, int);

	Character* getCharacter();

	void setMessage(string);
	string getMessage();

	string getBuilding();

	void showInteractions();
	//returns the refernce returne from this interaction
	//It may return the index of a dungeon or a boolean if the monster in it is dead
	// int doInteraction(int);

	int getRef();
};

#endif