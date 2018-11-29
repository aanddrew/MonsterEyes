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
		//load the game --NOT NEEDED IN THIS BLOCK
		//the game is loaded automatically at the end of the next block
		//if the player says N then the game will generate a new game file, then load it
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
			outputFile << "1" << endl;
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
					string type ="";
					int i;
					for (i = 0; i < s.length() && s[i] != ','; i++)
					{
						type += s[i];
					}
					i++;

					if (type == "Armor" || type == "Weapon")
					{
						string name;
						//Health or Damage
						int HealthorDamage;
						int slot;
						string temp;
						for (; i < s.length() && s[i] != ','; i++)
						{
							name += s[i];
						}
						i++;
						for (; i < s.length() && s[i] != ','; i++)
						{
							temp += s[i];
						}
						i++;
						HealthorDamage = stoi(temp);

						if (type == "Armor")
						{
							temp = "";
							for (; i < s.length(); i++)
							{
								temp += s[i];
							}
							slot = stoi(temp);

							Armor * a = new Armor(name, HealthorDamage, slot);
							p.getInventory()->push_back(a);
						}
						else
						{
							Weapon * w = new Weapon(name, HealthorDamage);
							p.getInventory()->push_back(w);
						}
					}
					if (type == "HealthPot")
					{
						string name;
						string temp;
						int health;
						for (; i < s.length()&&s[i] != ','; i++)
						{
							name += s[i];
						}
						i++;
						for (; i< s.length(); i++)
						{
							temp += s[i];
						}
						health = stoi(temp);

						HealthPot * h = new HealthPot(name, health);
						p.getInventory()->push_back(h);
					}
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
					//add the item to their inventory
					string type ="";
					int i;
					for (i = 0; i < s.length() && s[i] != ','; i++)
					{
						type += s[i];
					}
					i++;

					if (type == "Armor" || type == "Weapon")
					{
						string name;
						//Health or Damage
						int HealthorDamage;
						int slot;
						string temp = "";
						for (; i < s.length() && s[i] != ','; i++)
						{
							name += s[i];
						}
						i++;
						for (; i < s.length() && s[i] != ','; i++)
						{
							temp += s[i];
						}
						i++;
						HealthorDamage = stoi(temp);

						temp = "";
						if (type == "Armor")
						{
						
							for (; i < s.length(); i++)
							{
								temp += s[i];
							}
							slot = stoi(temp);

							Equipable * a = new Armor(name, HealthorDamage, slot);
							p.setWearing(a->getSlot(), true);
							p.getWearing()[a->getSlot()] = a;
						}
						else
						{
							Equipable * w = new Weapon(name, HealthorDamage);
							p.setWearing(0,true);
							p.getWearing()[0] = w;
						}
					}
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
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//        LOAD GAME ENDED
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// void enterRoom();
// void enterDungeon();

void Game::playGame()
{
	// p.showInfo();
	// p.showInventory();

	cout << "Welcome to Monster Eyes " << p.getName() << "!" << endl;
	string input;

	// cout << p.isWearing(4) << endl;

	int choice = 0;
	while(p.alive() && input != "Q")
	{
		//if the player is just sitting in the outer zone
		if (currentRoom == -1 && currentDungeon == -1)
		{
			cout << "You are currently in Zone " << currentZone + 1 << "." << endl;
			cout << "Would you like to: " << endl;
			cout << "\tEnter a building? (1)" << endl;
			cout << "\tGo to the previous zone? (2)" << endl;
			cout << "\tGo to the next zone? (3)" << endl;
			showPlayerOptions();
			showSaveOptions();

			cin >> input;

			if(!getPlayerOptions(input) && !getSaveOptions(input))
			{
				choice = stoi(input);
				switch(choice)
				{
					case 1:
					{
						cout << "Which building would you like to enter?" << endl;
						int i;
						for (i = 0; i < zones[currentZone].getRooms()->size(); i++)
						{
							cout << "\t(" << i << ") " 
								 << zones[currentZone].getRooms()->at(i)->getCharacter()->getName() << "'s "
								 << zones[currentZone].getRooms()->at(i)->getBuilding() << "?" << endl;
						}
						cout << "\t(" << i << ")" << " None?" << endl;

						cout << "\t(G) " << zones[currentZone].getFoodShop()->getCharacter()->getName() << "'s "
								 << zones[currentZone].getFoodShop()->getBuilding() << "?" << endl;
						cout << "\t(B) " << zones[currentZone].getItemShop()->getCharacter()->getName() << "'s "
								 << zones[currentZone].getItemShop()->getBuilding() << "?" << endl;

						cin >> input;

						if (input == "g" || input == "G")
						{
							currentRoom = -2;
						}
						else if (input == "b" || input == "B")
						{
							currentRoom = -3;
						}
						else
						{
							choice = stoi(input);
							if (choice < i)
							{
								currentRoom = choice;	
							}
						}
						break;
					}
					case 2:
					{
						if (currentZone == 0)
						{
							cout << "This is the first zone..." << endl;
						}
						else
						{
							currentZone--;
						}
						break;
					}
					case 3:
					{
						if (currentZone == numZones-1)
						{
							cout << "Sorry, there is no next zone!" << endl;
						}
						else if (p.getLevel() < zones[currentZone+1].getLevel())
						{
							cout << "You are not high enough level for that zone." << endl;
							cout << "\tYou must be level " << zones[currentZone+1].getLevel() << "." << endl;
						}
						else
						{
							currentZone++;
						}
						break;
					}
				}
			}
		}
		//if the player is in the food shop
		else if(currentRoom == -2)
		{
			cout << zones[currentZone].getFoodShop()->getCharacter()->getName() << " says: " << endl;
			cout << "\t" << zones[currentZone].getFoodShop()->getMessage() << endl;

			cout << "Would you like to: " << endl;
			cout << "\t(1) Buy some groceries?" << endl;
			cout << "\t(2) Leave the building?" << endl;
			cin >> input;

			choice = stoi(input);
			switch(choice)
			{
				case 1:
				{
					cout << "Here is our selection: " << endl;
					int i;
					int numFoods = 10;
					string names[numFoods];
					int healths[numFoods];
					int prices[numFoods];

					NameGenerator foodNames("food-names.txt");

					for (i=0; i < numFoods; i++)
					{
						names[i] = foodNames.getRandomName();
						healths[i] = rand() % ((zones[currentZone].getLevel()+1)*2) + 1;
						prices[i] = healths[i] + (rand()%3)*zones[currentZone].getLevel();
						cout << "\t(" << i << ") " << names[i] << " [" << healths[i] << " health]" << " - " << prices[i] << " gold." << endl;
					}
					cout << "\t(" << i << ") None?" << endl;
					cin >> input;
					choice = stoi(input);
					if (choice != i)
					{
						if(p.getGold() < prices[choice])
						{
							cout << "You don't have enough gold to buy that." << endl;
						}
						else if(p.getInventory()->size() == p.getInventory()->capacity())
						{
							cout << "Your inventory is full!" << endl;
						}
						else
						{
							p.setGold(p.getGold()-prices[choice]);
							HealthPot * h = new HealthPot(names[choice], healths[choice]);
							p.getInventory()->push_back(h);
							cout << "You just bought: " << names[choice] << " for " << prices[choice] << " gold." << endl;

						}
					}
					break;
				}
				case 2:
				{
					currentRoom = -1;
					break;
				}
			}

		}
		//if the player is in the blacksmith shop
		else if(currentRoom == -3)
		{
			cout << zones[currentZone].getItemShop()->getCharacter()->getName() << " says: " << endl;
			cout << "\t" << zones[currentZone].getItemShop()->getMessage() << endl;

			cout << "Would you like to: " << endl;
			cout << "\t(1) Buy some Armor/Weapons?" << endl;
			cout << "\t(2) Leave the building?" << endl;
			cin >> input;

			choice = stoi(input);
			switch(choice)
			{
				case 1:
				{
					int numItems = 10;
					int numWeps = rand() % (numItems -5) + 1;
					int numArms = 10-numWeps;
					NameGenerator wepNamesG("weapon-names.txt");

					//get a list of material names
					ifstream matFile("material-names.txt");
					string matNames[10];
					for (int i = 0; i < 10; i++)
					{
						getline(matFile, matNames[i]);
					}

					string wepNames[numWeps];
					int wepDamages[numWeps];

					for (int i = 0; i < numWeps; i++)
					{
						string matName;
						//levesl start at 1 go to-> 10
						if (currentZone != numZones-1)
						{
							matName = matNames[(zones[currentZone].getLevel()-1) + rand()%2];
						}
						else
						{
							matName = matNames[(zones[currentZone].getLevel()-1)];
						}
						string wepName = matName + " " + wepNamesG.getRandomName();
						wepNames[i] = wepName;
						wepDamages[i] = rand() % (zones[currentZone].getLevel()*4) + rand() % zones[currentZone].getLevel() + 1;
						// cout << wepNames[i] << " " << wepDamages[i] << endl;
					}

					string armNames[numArms];
					int armHealths[numArms];
					int armSlots[numArms];

					for (int i = 0; i < numArms; i++)
					{
						string matName;
						//levesl start at 1 go to-> 10
						if (currentZone != numZones-1)
						{
							matName = matNames[(zones[currentZone].getLevel()-1) + rand()%2];
						}
						else
						{
							matName = matNames[(zones[currentZone].getLevel()-1)];
						}

						string armName = matName + " ";

						int slot = rand()%4 + 1;

						switch(slot)
						{
							case 1:
							{
								int x = rand()%3;
								switch(x)
								{
									case 0: armName += "Boots";
										break;
									case 1: armName += "Shoes";
										break;
									case 2: armName += "Sandals";
										break;
								}
								break;
							}
							case 2:
							{
								int x = rand()%3;
								switch(x)
								{
									case 0: armName += "Legs";
										break;
									case 1: armName += "Pants";
										break;
									case 2: armName += "Trousers";
										break;
								}
								break;
							}
							case 3:
							{
								int x = rand()%3;
								switch(x)
								{
									case 0: armName += "Shirt";
										break;
									case 1: armName += "Chest";
										break;
									case 2: armName += "Jacket";
										break;
								}
								break;
							}
							case 4:
							{
								int x = rand()%3;
								switch(x)
								{
									case 0: armName += "Hat";
										break;
									case 1: armName += "Helm";
										break;
									case 2: armName += "Crown";
										break;
								}
								break;
							}
						}
						armSlots[i] = slot;
						armNames[i] = armName;
						armHealths[i] = rand() % (zones[currentZone].getLevel()*4) + 1;

						// cout << armNames[i] << " " << armHealths[i] << " " << armSlots[i] << endl;
					}

					int prices[numItems];
					for (int i = 0; i < numItems; i++)
					{
						if (i < numWeps)
						{
							prices[i] = rand() % (4*zones[currentZone].getLevel()) + wepDamages[i];
						}
						else
						{
							prices[i] = rand() % (4*zones[currentZone].getLevel()) + armHealths[i-numWeps];
						}
					}

					int i;
					for (i = 0; i < numItems; i++)
					{
						if (i < numWeps)
						{
							cout << "(" << i << ") " << wepNames[i] << " [" << wepDamages[i] << " damage]";
						}
						else
						{
							cout << "(" << i << ") " << armNames[i-numWeps] << " [" << armHealths[i-numWeps] << " health]";
						}
						cout << " - " << prices[i] << " gold" << endl;
					}
					cout << "(" << i << ") None?" << endl;
					cout << "Which item would you like to purchase?" << endl;
					cin >> input;

					choice = stoi(input);
					if (choice != i)
					{
						if(p.getGold() < prices[choice])
						{
							cout << "You don't have enough gold to buy that." << endl;
						}
						else if(p.getInventory()->size() == p.getInventory()->capacity())
						{
							cout << "Your inventory is full!" << endl;
						}
						else
						{
							p.setGold(p.getGold()-prices[choice]);
							if (choice < numWeps)
							{
								Weapon * w = new Weapon(wepNames[choice], wepDamages[choice]);
								p.getInventory()->push_back(w);
								cout << "You just bought: " << wepNames[choice] << " for " << prices[choice] << " gold." << endl;
							}
							else
							{
								Armor * a = new Armor(armNames[choice-numWeps], armHealths[choice-numWeps], armSlots[choice-numWeps]);
								p.getInventory()->push_back(a);
								cout << "You just bought: " << armNames[choice-numWeps] << " for " << prices[choice] << " gold." << endl;
							}
						}
					}
				}
				case 2:
				{
					currentRoom = -1;
				}
			}
		}
		else if(currentDungeon == -1)
		{
			//I will be accessing the current room a lot
			//this is for readability and my own sanity
			Room * currentRoomP = zones[currentZone].getRooms()->at(currentRoom);

			cout << "You are currently in " << currentRoomP->getCharacter()->getName() << "'s " <<
					currentRoomP->getBuilding() << "." << endl;

			bool inRoom = true;
			while (inRoom)
			{
				cout << "Would you like to: " << endl;
				
				cout << "\tTalk to " << currentRoomP->getCharacter()->getName() << "? (1)" << endl;
				cout << "\tLeave the building? (2)" << endl;

				showPlayerOptions();
				cin >> input;

				if(!getPlayerOptions(input))
				{
					choice = stoi(input);
					switch(choice)
					{
						case 1:
						{
							cout << currentRoomP->getCharacter()->getName() << " says: " <<
							currentRoomP->getMessage() << "?" << endl;
							cout << "\t(Y)es or (N)o?" << endl;

							cin >> input;

							if (input == "y" || input == "Y")
							{
								//this is supposed to start the dungeon loop
							}
							if (input == "n" || input == "N")
							{
								int x = rand() % 3;
								switch (x)
								{
									case 0: cout << currentRoomP->getCharacter()->getName() << " says: Goodbye!" << endl;
										break;
									case 1: cout << currentRoomP->getCharacter()->getName() << " says: Cya Later!" << endl;
										break;
									case 2: cout << currentRoomP->getCharacter()->getName() << " says: Okay, may our paths cross again..." << endl;
										break;
								}
								
							}
							break;
						}
						case 2:
						{
							currentRoom = -1;
							inRoom = false;
							break;
						}
					}
				}
			//while (input != "L") ends
			}
		//else if(currentDungeon == -1) ends
		}
	//while(p.alive() && input != "Q") ends
	}
//playGame() ends
}

void Game::saveGame()
{
	ifstream inputFile("Game.txt"); //File to read from
	ofstream outputFile("GameTemp.txt"); //temp

	cout << "Saving..." << endl;


	outputFile << "G" << endl;
	outputFile << currentZone << endl;
	outputFile << currentRoom << endl;
	outputFile << currentDungeon << endl;
	outputFile << "endG" << endl;

	outputFile << "P" << endl;
	//player stats
	outputFile << p.getName() << endl;
	outputFile << p.getLevel() << endl;
	outputFile << p.getXP() << endl;
	outputFile << p.getGold() << endl;
	outputFile << p.getHealth() << endl;
	outputFile << p.getMaxHealth() << endl;
	outputFile << p.getMaxDamage() << endl;

	outputFile << "I" << endl;
	int k;
	for (k = 0; k < p.getInventory()->size(); k++)
	{
		Item * item = p.getInventory()->at(k);

		if (dynamic_cast<Armor*>(item) != nullptr)
		{
			Armor * a = dynamic_cast<Armor*>(item);
			outputFile << "Armor" << ",";
			outputFile << a->getName() << ",";
			outputFile << a->getExtraHealth() << ",";
			outputFile << a->getSlot() << endl;
		}
		else if (dynamic_cast<Weapon*>(item) != nullptr)
		{
			Weapon * w = dynamic_cast<Weapon*>(item);
			outputFile << "Weapon,";
			outputFile << w->getName() << ",";
			outputFile << w->getMaxDamage() << endl;
		}
		else if (dynamic_cast<HealthPot*>(item) != nullptr)
		{
			HealthPot * h = dynamic_cast<HealthPot*>(item);
			outputFile << "HealthPot,";
			outputFile << h->getName() << ",";
			outputFile << h->getHealth() << endl;
		}
	}
	for (; k < p.getInventory()->capacity(); k++)
	{
		outputFile << "NULL" << endl;
	}
	outputFile << "endI" << endl;

	outputFile << "W" << endl;
	for (k = 0; k < 5; k++)
	{
		if (p.isWearing(k))
		{
			Item * item = p.getWearing()[k];

			if (dynamic_cast<Armor*>(item) != nullptr)
			{
				Armor * a = dynamic_cast<Armor*>(item);
				outputFile << "Armor" << ",";
				outputFile << a->getName() << ",";
				outputFile << a->getExtraHealth() << ",";
				outputFile << a->getSlot() << endl;
			}
			else if (dynamic_cast<Weapon*>(item) != nullptr)
			{
				Weapon * w = dynamic_cast<Weapon*>(item);
				outputFile << "Weapon,";
				outputFile << w->getName() << ",";
				outputFile << w->getMaxDamage() << endl;
			}
		}
		else
		{
			outputFile << "NULL" << endl;
		}
	}
	outputFile << "endW" << endl;
	outputFile << "endP" << endl;

	string temp;
	int i = 1;
	while (getline(inputFile, temp))
	{
		if (i > 43)
		{
			//re-write the old stuff
			outputFile << temp << endl;
		}
		i++;
	}
	outputFile.close();
	inputFile.close();


	//now the contents of the game currently (the newGame) are stored in GameTemp.txt
	//so I open Game.txt as the oldGame, and GameTemp as newGame
	ofstream oldGame("Game.txt", std::ofstream::out | std::ofstream::trunc);
	ifstream newGame("GameTemp.txt");

	//copy contents from newGame into the oldGame File.
	while(getline(newGame,temp))
	{
		oldGame << temp << endl;
	}

	cout << "Done!" << endl;
}

void Game::showPlayerOptions()
{
	cout << "\tShow your stats? (S)" << endl;
	cout << "\tShow your Inventory? (I)" << endl;
}

void Game::showSaveOptions()
{
	cout << "\tSave the game? (SA)" << endl;
}

bool Game::getSaveOptions(string input)
{
	if (input == "sa" || input == "SA")
	{
		saveGame();
		return true;
	}
	return false;
}

bool Game::getPlayerOptions(string input)
{
	if (input == "S" || input == "s")
	{
		p.showInfo();
		return true;
	}
	else if(input == "I" || input == "i")
	{
		p.showInventory();
		return true;
	}
	return false;
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