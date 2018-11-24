#include <iostream>

#include "Character.h"
#include "Item.h"
#include "Equipable.h"
#include "Armor.h"
#include "Game.h"
#include "Player.h"
#include "Zone.h"
#include "Room.h"

using namespace std;

int main()
{
	Game g;

	g.playGame();


	// Character c(1.0,1.0);

	// cout << c.getHealth() << endl;
	// cout << c.getInventorySize() << endl;

	// for (int i = 0; i <c.getInventorySize(); i++)
	// {
	// 	cout << c.getItemAt(i).getName() << endl;
	// }

	// cout << c.getMaxHealth() << endl;

	// float x = 4.2;
	// Armor a("this is the armors name", x, 2);

	// Equipable * e = &a;

	// e->equip(c);

	// cout << c.getMaxHealth() << endl;
 
	// // // a.equip();

	return 0;
}