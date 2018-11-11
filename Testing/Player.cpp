#include "Player.h"

Player::Player()
{
	maxHP = 10;
	health = 10;
	level = 1;
}

Player::Player(float healthIn)
{
	health = healthIn;
	maxHP = healthIn;

	level = 1;
}

void Player::levelUp()
{
	maxHP += 5;

	level++;
}

int Player::getLevel()
{
	return level;
}