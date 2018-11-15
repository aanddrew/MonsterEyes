#include <iostream>

#include "Character.h"
#include "Item.h"
#include "Equipable.h"
#include "Armor.h"

using namespace std;

int main()
{
	Character c(1.0,1.0);

	cout << c.getHealth() << endl;
	cout << c.getInventorySize() << endl;

	for (int i = 0; i <c.getInventorySize(); i++)
	{
		cout << c.getItemAt(i).getName() << endl;
	}

	float x = 4.2;
	// Armor e("hello", x, 2);
	Armor a("this is the armors name", x, 2);

	Equipable * e = &a;

	e->equip();

	// a.equip();

	return 0;
}