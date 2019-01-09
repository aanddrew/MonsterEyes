/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <string>
#include <vector>

using namespace std;

class NameGenerator
{
private:
	string fileName;
	// int numNamesInFile;
	vector<string> names;
	// vector<int> namesUsed;
public:
	NameGenerator(string);
	string getRandomName();
};

#endif