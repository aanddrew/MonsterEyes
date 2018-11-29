#include <iostream>

#include "Player.h"

using namespace std;

Player::Player() : Character("Andrew", 5.0)
{
	
}

Player::Player(string nameIn) : Character(nameIn, 5.0)
{
	this->setMaxDamage(1);
}

void Player::showInventory()
{
	cout << this->getName() << "'s Inventory: (Maximum size: " << this->getInventory()->capacity() << ")" << endl;
	if (this->getInventory()->size() == 0)
	{
		cout <<"\tNo Items in inventory currently." << endl;
	}
	int i;
	for (i = 0; i < this->getInventory()->size(); i++)
	{
		cout << "\t" <<  i << ": " << this->getInventory()->at(i)->getName() << endl;
	}
	

	if (this->getInventory()->size() != 0)
	{
		cout << "Select an item to interact with. (E to exit)" << endl;
		string temp;
		cin >> temp;
		if (temp != "E" && temp != "e")
		{
			int choice = stoi(temp);
			cout << "\t" << this->getInventory()->at(choice)->getInfo() << endl;
			cout << "\tWould you like to " << this->getInventory()->at(choice)->getInteraction() << " " << 
					this->getInventory()->at(choice)->getName() << "?" << endl;
			cout << "\t(Y)es or (N)o?" << endl;

			string input;
			cin >> input;
			if (input == "Y" || input == "y")
			{
				this->getInventory()->at(choice)->interact(this);
			}
		}
	}
}

void Player::levelUp()
{
	//performs normal level up, but also gives the player feedback.
	this->Character::levelUp();
	cout << "You are now level " << this->getLevel() << "!" << endl;
	cout << "You now have " << this->getMaxHealth() << " max health and have been fully healed." << endl;
}

void Player::showInfo()
{
	//printing various things
	cout << "Info for " << this->getName() << ":" << endl;
	cout << "\t" << "Level: " << this->getLevel() << endl;
	cout << "\t" << "XP: " << this->getXP() << endl;
	cout << "\t" << "Current Health: " << this->getHealth() << endl;
	cout << "\t" << "Max Health: " << this->getMaxHealth() << endl;
	cout << "\t" << "Gold: " << this->getGold() << endl;
	cout << "\tMax Damage: " << this->getMaxDamage() << endl;
	cout << "\t" << "Equipped:" << endl;
	for (int i = 0; i < 5; i++)
	{
		//if the player is wearing something in that slot ~print it
		if (this->isWearing(i))
			cout << "\t\t ("<< i <<") " << this->getWearing()[i]->getName() << endl; 	
		else
			cout << "\t\t ("<<i<<") -N/a-" << endl;
	}

	bool isEquipped = false;
	for (int i = 0; i < 5; i++)
	{
		if (this->isWearing(i)) isEquipped= true;
	}
	if (isEquipped)
	{
		cout << "Would you like to unequip any items?" << endl;
		cout << "\t(Y)es or (N)o?" << endl;
		string input;
		cin >> input;

		if (input == "Y" || input == "y")
		{
			cout << "Which one? (Look at the numbers) (N to go back)" << endl;
			cin >> input;
			if (input != "N" && input != "n")
			{
				int choice = stoi(input);
				this->getWearing()[choice]->unequip(this);
			}
		}
	}
}
