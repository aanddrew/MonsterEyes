/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#include <iostream>

#include "NameGenerator.h"
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

NameGenerator::NameGenerator(string fileName)
{
	ifstream inputFile;

	inputFile.open(fileName, ios::in);
	names.reserve(5000);

	if(inputFile.is_open())
	{
		string name;
		while(getline(inputFile, name))
		{
			names.push_back(name);
		}
	}
}

string NameGenerator::getRandomName()
{
	int i = rand() % names.size();
	return names.at(i);
}