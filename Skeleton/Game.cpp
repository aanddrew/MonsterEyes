#include <cstdlib>
#include <iostream>
#include <string>

#include "Game.h"
#include "Armor.h"
#include "Item.h"

using namespace std;

Game::Game()
{
	srand(time(0));
	currentZone = 1;
	currentRoom = -1;
	currentDungeon = -1;

	generateZones();
}

/*
Generates the array of zones for the game to use.
*/
void Game::generateZones()
{
	for (int i = 0; i < 10; i++)
	{
		Zone z(i);
		zones[i] = z;
	}
}

/*
Changes the zone of the player
*/
void Game::changeZone(int zoneNum)
{
	if (p.getLevel() >= zones[zoneNum].getLevel())
	{
		currentZone = zoneNum;
	}
}

// void enterRoom();
// void enterDungeon();

/*
This is going to be the main game function.
There will be a main.cpp and it will call this function
*/
void Game::playGame()
{
	cout << "I am in zone " << currentZone << endl;

	cout << "My player has " << p.getMaxHealth() << " max health" << endl;

	p.setLevel(1);
	changeZone(2);
	cout << "I am now in zone: " << currentZone << endl;

	Armor e("Wood Helm", 4.2, 4);

	Armor l("Wood Legs", 5.3, 2);

	e.equip(&p);
	l.equip(&p);

	cout << "My player has " << p.getMaxHealth() << " max health" << endl;

	Weapon w("Bronze sword", 5);

	cout << w.getDamage() << endl;

	Character john("John", 5.0);
	string building = "Tavern";
	string message = "Will you go to the rat's lair for me???";
	Character *c = &john;
	Room r(&john, building, message, 2);

	r.showInteractions();

	cout << r.doInteraction(1) << endl;
}