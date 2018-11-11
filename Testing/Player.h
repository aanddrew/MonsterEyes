#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
{
private:
	float maxHP;
	float health;
	int level;


public:
	Player();

	Player(float);

	void levelUp();

	int getLevel();
};

#endif