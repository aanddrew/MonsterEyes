#include <iostream>

#include "Player.h"

using namespace std;

Player::Player() : Character("Andrew", 5.0)
{
	
}

Player::Player(string nameIn) : Character(nameIn, 5.0)
{

}

void Player::displayInventory()
{
	cout << "Player Inventory: " << endl;
	for (int i = 0; i < this->getInventory()->size(); i++)
	{
		cout << i << ": " << this->getInventory()->at(i)->getName() << endl;
	}
}