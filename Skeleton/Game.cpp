#include <cstdlib>
#include <iostream>
#include <string>

#include "Game.h"
#include "Armor.h"
#include "Item.h"
#include "NameGenerator.h"

using namespace std;

Game::Game():numZones(10)
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
		//the game is loaded automatically at the end of this block
	}
	else if(input == "N" || input == "n")
	{
		//open the file Game.txt and clear the contents
		//we will use this to store the game in the file.
		ofstream outputFile("Game.txt", std::ofstream::out | std::ofstream::trunc);

		//create the state of the game first
		outputFile << "G" << endl;
		outputFile << "0" << endl << "-1" << endl << "-1" << endl;
		outputFile << "endG" << endl;

		//these name generators will generate the random rooms and dungeons, etc..
		NameGenerator firstNames("first-names.txt");
		NameGenerator buildingNames("building-names.txt");
		NameGenerator enemyNames("enemy-names.txt");
	
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
			//max Damage
			outputFile << "1" << endl;

			//beginning of inventory contents, all are null at start
			outputFile << "I" << endl;
			for (int i = 0; i < 20; i++)
			{
				outputFile << "NULL" << endl;
			}
			outputFile << "endI" << endl;

			//beginning of wearing contents, all are null at start
			outputFile << "W" << endl;
			for (int i = 0; i < 5; i ++)
			{
				outputFile << "NULL" << endl;
			}
			outputFile << "endW" << endl;
		}
		outputFile << "endP" << endl;

		//this block for writing each zone
		for (int i = 0; i < numZones; i++)
		{
			int level = i +1;
			outputFile << "Z" << endl;
			outputFile << level << endl;
			
			//this will store the names of the creatures, so that I can create
			//a special message for each of the buildings
			string enemies[4+i*2];

			//this block for writing the dungeons
			//we must write the dungeons first so that the buildings know the type
			//	of enemy inside their referenced dungeon
			outputFile << "D" << endl;
			for (int j = 0; j < 4+i*2; j++)
			{
				string enemy = enemyNames.getRandomName();
				enemies[j] = enemy;
				int len = rand() % 3+4;
				int dmg = rand() % 4 + 3* i + 1;

				//this line represents one dungeon -------------
				outputFile << enemy << "," << len << "," << dmg << endl;
			}
			outputFile << "endD" << endl;

			//this block for writing the buildings.
			outputFile << "B" << endl;
			for (int j = 0; j < 4+i*2; j++)
			{
				string firstName = firstNames.getRandomName();
				string buildingName = buildingNames.getRandomName();

				string message;

				int x = rand() %3;
				switch (x)
				{
					case 0: message = "Will you defeat the house of " + enemies[j] + "s for me?";
						break;
					case 1: message = "Can you go beat up those " + enemies[j] + "s for me?";
						break;
					case 2: message = "Would you please go kill all those " + enemies[j] + "s in their Lair?";
						break;
				}

				//this line represents one building -----------
				outputFile << firstName << "," << buildingName.c_str() << "," << message << "," << j << endl;
			}
			outputFile << "endB" << endl;
			outputFile << "endZ" << endl;
		}
		outputFile.close();
	}


	loadGame();
}

void Game::loadGame()
{
	ifstream inputFile("Game.txt");

	string s;
	while (getline(inputFile, s))
	{
		//get the current zone, room, or dungeon
		if (s=="G")
		{
			getline(inputFile,s);
			currentZone = stoi(s);
			getline(inputFile,s);
			currentRoom = stoi(s);
			getline(inputFile,s);
			currentDungeon = stoi(s);
		}
		//access the lines inside the player block
		//grab the values in the text file and assign them to
		//a temporary player object.
		//we then assign the Player p data member to the address of this temp object
		if (s == "P")
		{
			Player pTemp;
			int val;

			getline(inputFile,s);
			pTemp.setName(s);
			//1
			getline(inputFile,s); val = stoi(s);
			pTemp.setLevel(val);
			//2
			getline(inputFile,s); val = stoi(s);
			pTemp.setXP(val);
			//3
			getline(inputFile,s); val = stoi(s);
			pTemp.setGold(val);
			//4
			getline(inputFile,s); val = stoi(s);
			pTemp.setHealth(val);
			//5
			getline(inputFile,s); val = stoi(s);
			pTemp.setMaxHealth(val);
			//6
			getline(inputFile,s); val = stoi(s);
			pTemp.setMaxDamage(val);

			p = pTemp;
		}
		//inventory checking...
		if (s== "I")
		{
			while (getline(inputFile,s))
			{
				if (s != "NULL")
				{
					//add the item to their inventory
				}

				if (s== "endI")
				{
					break;
				}
			}
		}
		//wearing checking...
		if(s == "W")
		{
			while (getline(inputFile,s))
			{
				if (s != "NULL")
				{
					//add this item to their wearing stack
				}

				if (s == "endW")
				{
					break;
				}
			}
		}

		//first zone spotted, move onto getting all zones.
		if (s == "Z")
		{
			//proceed with zone stuff
			//First we get the level and place a new zone into
			// the array of zones
			getline(inputFile,s);
			//the level of the zone
			int lev = stoi(s);
			//index of this zone in the array
			int index = lev -1;
			zones[index] = Zone(lev*1, 4+(index*2), 4+(index*2));

			int i = 0;
			while (getline(inputFile,s) && s != "endD")
			{
				if (s != "D")
				{
					// cout << s << endl;
					string enemy_name = "";

					string temp = "";
					int numRooms;
					int maxDamage;
					//level = lev (already have that variable)

					int l;
					for (l = 0; l < s.length() && s[l] != ','; l++)
					{
						enemy_name += s[l];					}
					// cout << enemy_name;
					l++;
					for (; l< s.length() && s[l] != ','; l++)
					{
						temp += s[l];
					}
					numRooms = stoi(temp);
					// cout << numRooms;
					temp = "";
					l++;
					for (; l < s.length(); l++)
					{
						// cout << s[l] << endl;
						temp += s[l];
					}
					maxDamage = stoi(temp);
					// cout << maxDamage << endl;

					// cout << enemy_name << numRooms << 

					//have to use new operator so that it creates
					//the object on the heap and thus gives it a permanent address
					zones[index].getDungeons()->push_back(new Dungeon(enemy_name, numRooms, maxDamage, lev));
					// cout << zones[index].getDungeons()->at(0) << endl;
					i++;
				}
			}

			while (getline(inputFile,s) && s!= "endB")
			{
				if (s != "B")
				{
					string npc_name = "";
					string building_name = "";
					string message = "";
					string temp = "";
					int ref;

					int l;
					for (l = 0; l < s.length() && s[l] != ','; l++)
					{
						npc_name += s[l];
					}
					l++;
					for (; l< s.length() && s[l] != ','; l++)
					{
						building_name += s[l];
					}
					l++;
					for (; l< s.length() && s[l] != ','; l++)
					{
						message += s[l];
					}
					l++;
					for (; l < s.length(); l++)
					{
						temp += s[l];
					}
					ref = stoi(temp);

					//create a character on the heap for the game to use
					Character * npc = new Character(npc_name, 5);

					//create a room on the heap for the game to use.
					zones[index].getRooms()->push_back(new Room(npc, 
																building_name,
																message,
																ref));
				}
				// cout << s << endl;
			}
		}

		// cout << s << endl;
	}
}

/*
Generates the array of zones for the game to use.
*/
void Game::generateZones()
{
	//this function does nothing right now	
// 	for (int i = 0; i < 10; i++)
// 	{
// 		Zone z(i+1);
// 		zones[i] = z;
// 	}
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

void Game::testGame4()
{
	p.showInfo();

	//this prints out the information about the dungeons as usable by the game
	// for (int z = 0; z < numZones; z++)
	// {
	// 	cout << " -------- Zone " << z << " -----" << endl;
	// 	for (int i = 0; i < zones[z].getNumRooms(); i++)
	// 	{
	// 		string mName = zones[z].getDungeons()->at(i)->getMonsterName();
	// 		cout << "This dungeon has " << 
	// 				zones[z].getDungeons()->at(i)->getRooms()->capacity() <<
	// 				" rooms full of " << mName << "s " << "that do " << 
	// 				zones[z].getDungeons()->at(i)->getRooms()->at(0)->getCharacter()->getMaxDamage() <<
	// 				" max damage" <<
	// 				" that have " << zones[z].getDungeons()->at(i)->getRooms()->at(0)->getCharacter()->getMaxHealth() <<
	// 				" max health" << endl;
	// 	}
	// }	

	//now lets do the buildings...
	for (int z = 0; z < numZones; z++)
	{
		cout << " -------- Zone " << z << " -----" << endl;
		for (int i = 0; i < zones[z].getNumRooms(); i++)
		{
			cout << zones[z].getRooms()->at(i)->getCharacter()->getName() <<
			"'s " << zones[z].getRooms()->at(i)->getBuilding() << 
			" sends you to a dungeon full of " <<
			zones[z].getDungeons()->at(i)->getMonsterName() << "s" <<endl;

			cout << "\t";
			cout << "These " << zones[z].getDungeons()->at(i)->getMonsterName() << "s" <<
				 	" do up to " << zones[z].getDungeons()->at(i)->getRooms()->at(0)->getCharacter()->getMaxDamage() <<
				 	" damage" << endl;
			cout << "\t";
			cout << "If one of them attacked you right now it would do " <<
				 zones[z].getDungeons()->at(i)->getRooms()->at(0)->getCharacter()->getDamageDealt() << " damage." << endl;
		}
	}
}