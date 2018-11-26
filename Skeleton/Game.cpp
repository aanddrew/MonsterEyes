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
	currentZone = 0;
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
		Zone z(i+1);
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
void Game::testGame()
{
	cout << "I am in zone " << currentZone << endl;

	cout << "My player has " << p.getMaxHealth() << " max health" << endl;

	p.setLevel(2);
	changeZone(1);
	cout << "I am now in zone: " << currentZone << endl;

	Armor e("Wood Helm", 4, 4);

	Armor l("Wood Legs", 5, 2);

	Equipable * eq = &e;

	eq->equip(&p);
	l.equip(&p);

	cout << "My player has " << p.getMaxHealth() << " max health" << endl;

	Weapon w("Bronze sword", 5);

	w.equip(&p);

	cout << p.getDamageDealt() << endl;

	// w.unequip(&p);

	cout << p.getDamageDealt() << endl;
	cout << (p.getWearing()[0] != NULL) << endl;

	Character john("John", 5.0);
	string building = "Tavern";
	string message = "Will you go to the rat's lair for me???";
	Character *c = &john;
	Room r(&john, building, message, 2);

	r.showInteractions();

	cout << r.doInteraction(1) << endl;

	p.getInventory()->push_back(&w);
	p.getInventory()->push_back(&l);
	p.getInventory()->push_back(&e);

	HealthPot healthPot(5);

	cout << p.getInventory()->size() << endl;

	p.getInventory()->push_back(&healthPot);

	p.levelUp();
	cout << p.getMaxHealth() << endl;

	p.setHealth(p.getHealth()-6);

	cout << "Player has " << p.getHealth() << " health" << endl;

	healthPot.consume(&p);

	cout << "Player has " << p.getHealth() << " health" << endl;	

	for (int i = 0; i < p.getInventory()->size(); i++)
	{
		cout << p.getInventory()->at(i)->getName() << endl;
		cout << p.getInventory()->at(i)->getInfo() << endl;
	}

	p.displayInventory();
}

void Game::testGame2()
{
	
}