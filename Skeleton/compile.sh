#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
#g++ test.cpp Game.cpp Character.cpp Item.cpp Equipable.cpp Armor.cpp Weapon.cpp -o test.o && ./test.o

g++ -std=c++11 ./*.cpp -o main.o && ./main.o
exit 0
