#ifndef ROOM_H
#define ROOM_H

class Room
{
private:
	Character c;
public:
	void showInteractions();
	//returns true if the player is still interacting with this Room
	bool doInteraction(int);
};

#endif