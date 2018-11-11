#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <string>
#include <vector>

using namespace std;

class NameGenerator
{
private:
	string fileName;
	int numNamesInFile;
	vector<string> names;
	vector<int> namesUsed;
public:
	NameGenerator(string);
	string getRandomName();
};

#endif