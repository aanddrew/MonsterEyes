#include <iostream>

#include "Character.h"

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
	return 0;
}