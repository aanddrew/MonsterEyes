#ifndef ARMOR_H
#define ARMOR_H

class Armor : public Equipable
{
private:
	float extraHealth;
	int slot;
public:
	Armor(string, float, int)
};
#endif