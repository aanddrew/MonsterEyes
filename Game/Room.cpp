#include <iostream>

#include "Room.h"

using namespace std;

Room::Room(Character *cIn, string buildingIn, string messageIn, int refIn)
{
	building = buildingIn;
	message = messageIn;
	c = cIn;
	ref = refIn;
}

void Room::setMessage(string messageIn)
{
	message = messageIn;
}

string Room::getMessage()
{
	return message;
}

string Room::getBuilding()
{
	return building;
}

Character* Room::getCharacter()
{
	return c;
}

void Room::showInteractions()
{
	cout << "You are in " << c->getName() << "'s " << building << "." << endl;

	cout << c->getName() << " says: " << message << "." << endl;
}

//returns 0 if the interaction remains in this room
// int Room::doInteraction(int)
// {
// 	return ref;
// }

int Room::getRef()
{
	return ref;
}