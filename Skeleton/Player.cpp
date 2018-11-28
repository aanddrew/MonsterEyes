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
	for (int i = 0; i < this->getInventory()->size(); i++)
	{
		cout << "\t" <<  i << ": " << this->getInventory()->at(i)->getName() << endl;
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
	cout << "\t" << "Equipped:" << endl;
	for (int i = 0; i < 5; i++)
	{
		//if the player is wearing something in that slot ~print it
		if (this->isWearing(i))
			cout << "\t\t" << this->getWearing()[i]->getName() << endl; 	
		else
			cout << "\t\t-N/a-" << endl;
	}
	cout << "\tMax Damage: " << this->getMaxDamage() << endl;
}
