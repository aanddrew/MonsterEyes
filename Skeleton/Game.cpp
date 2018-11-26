#include <cstdlib>
#include <iostream>
#include <string>

#include "Game.h"
#include "Armor.h"
#include "Item.h"
#include "NameGenerator.h"

using namespace std;

Game::Game()
{
	srand(time(0));

	cout << "Would you like to: \n" <<
			"\tLoad Game? (L)\n" << 
			"\tOr\n" <<
			"\tCreate a new game? (N)" << endl;

	string input;
	cin >> input;
	if (input == "L" || input == "l")
	{
		//load the game
	}
	else if(input == "N" || input == "n")
	{
		NameGenerator firstNames("first-names.txt");
		NameGenerator buildingNames("building-names.txt");
		NameGenerator enemyNames("enemy-names.txt");
		//open the file Game.txt and clear the contents
		ofstream outputFile("Game.txt", std::ofstream::out | std::ofstream::trunc);

		cout << "What is your name, adventurer?" << endl;
		cin >> input;

		//this block for writing the information about the player
		outputFile << "P" << endl;
		{
			//player name
			outputFile << input << endl;

			p = Player(input);
			//player level
			outputFile << "0" << endl;
			//player xp
			outputFile << "0" << endl;
			//amount of gold
			outputFile << "10" << endl;
			//amount of health
			outputFile << "10" << endl;
			//max health
			outputFile << "10" << endl;


			outputFile << "I" << endl;
			for (int i = 0; i < 20; i++)
			{
				outputFile << "" << endl;
			}
			outputFile << "endI" << endl;



			outputFile << "W" << endl;
			for (int i = 0; i < 5; i ++)
			{
				outputFile << "" << endl;
			}
			outputFile << "endW" << endl;
		}
		outputFile << "endP" << endl;

		//this block for writing each zone
		for (int i = 0; i < 10; i++)
		{
			int level = i +1;
			outputFile << "Z" << endl;
			outputFile << level << endl;
			//begin creating dungeons
			outputFile << "D" << endl;
			for (int j = 0; j < 4+i*2; j++)
			{
				string enemy = enemyNames.getRandomName();
				int len = rand() % 3+4;
				int dmg = rand() % 4 + 3* i + 1;

				outputFile << enemy << "," << len << "," << dmg << endl;
			}
			outputFile << "endD" << endl;

			outputFile << "B" << endl;
			//begin the buildings
			for (int j = 0; j < 4+i*2; j++)
			{
				string firstName = firstNames.getRandomName();
				string buildingName = buildingNames.getRandomName();

				string message;

				outputFile << firstName << ","
						   << buildingName.c_str() << "," << j << endl;
			}
			outputFile << "endB" << endl;
			outputFile << "endZ" << endl;
		}

		loadGame();

		outputFile.close();
	}

	currentZone = 0;
	currentRoom = -1;
	currentDungeon = -1;

	generateZones();
}

void Game::loadGame()
{
	ifstream inputFile("Game.txt");

	string s;
	while (getline(inputFile, s))
	{
		cout << s << endl;
	}
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
These are a couple functions to test game functionality.
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

	p.showInventory();
}

void Game::testGame2()
{
	// Player p("John");

	Weapon sword("Wood sword", 5);
	Armor helm1("Wood Helm", 5, 4);
	Armor chest1("Stone chest", 7, 3);
	Armor legs1("Brone legs", 4, 2);
	Armor feet1("Leather feet", 3, 1);

	p.levelUp();

	p.getInventory()->push_back(&sword);
	p.getInventory()->push_back(&helm1);
	p.getInventory()->push_back(&chest1);
	p.getInventory()->push_back(&legs1);
	p.getInventory()->push_back(&feet1);

	sword.equip(&p);
	helm1.equip(&p);
	chest1.equip(&p);
	legs1.equip(&p);
	feet1.equip(&p);

	sword.unequip(&p);

	chest1.unequip(&p);

	p.showInventory();

	p.showInfo();
}

void Game::testGame3()
{
	// Player p("John");

	Character j("jeff", 5);
	Room r(&j, "tavern", "You have to go to the rat's lair", 5);

	cout << r.getMessage() << endl;

	Weapon sword("Wood sword", 5);
	Armor helm1("Wood Helm", 5, 4);
	Armor chest1("Stone chest", 7, 3);
	Armor legs1("Brone legs", 4, 2);
	Armor feet1("Leather feet", 3, 1);

	p.levelUp();

	p.getInventory()->push_back(&sword);
	p.getInventory()->push_back(&helm1);
	p.getInventory()->push_back(&chest1);
	p.getInventory()->push_back(&legs1);
	p.getInventory()->push_back(&feet1);

	sword.equip(&p);
	helm1.equip(&p);
	chest1.equip(&p);
	legs1.equip(&p);
	feet1.equip(&p);

	sword.unequip(&p);

	chest1.unequip(&p);

	p.showInventory();

	p.showInfo();
}