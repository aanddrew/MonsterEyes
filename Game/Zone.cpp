/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#include "Zone.h"

#include "NameGenerator.h"

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

	NameGenerator ng("first-names.txt");
	Character * c = new Character(ng.getRandomName(),5);
	foodShop = new Room(c, "groceries (Shop)", "Welcome to my grocery store! You can get all kinds of food here.", -1);

	Character *bc = new Character(ng.getRandomName(),5);
	itemShop = new Room(bc, "armor & weapons (Shop)", "Welcome to the shop. I'm your guy for Armor and Weapons.", -1);
}

vector<Dungeon*>* Zone::getDungeons()
{
	return &dungeons;
}

vector<Room*>* Zone::getRooms()
{
	return &rooms;
}

Room* Zone::getFoodShop()
{
	return foodShop;
}

Room* Zone::getItemShop()
{
	return itemShop;
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