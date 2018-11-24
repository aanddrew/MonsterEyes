#include "Zone.h"

using namespace std;

Zone::Zone()
{
	level = 1;
}

Zone::Zone(int levelIn)
{
	level = levelIn;	
}

// void showInteractions();
// void interact();

// void enterDungeon(int);

int Zone::getLevel()
{
	return level;
}
// Room getRoomAt(int);