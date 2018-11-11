#include <iostream>
#include <string>
#include <cstdlib>

#include <fstream>

#include "NameGenerator.h"

using namespace std;

int main()
{
	NameGenerator n("first-names.txt");

	// cout << n.getRandomName() << endl;

	for (int i = 0; i < 100; i++)
	{
		srand(time(0)+rand());
		cout << n.getRandomName() << endl;
	}

	ofstream outputFile;
	outputFile.open("towns.txt", ios::app);

	for (int i = 0; i < 100; i++)
	{
		srand(time(0)+rand());
		outputFile << n.getRandomName() << endl;
	}

	// outputFile.close();

	// outputFile.open("towns.txt");

	for (int i = 0; i < 100; i++)
	{
		outputFile << i << endl;
	}
	return 0;
}