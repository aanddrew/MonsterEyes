#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++ test.cpp Character.cpp Item.cpp Equipable.cpp Armor.cpp -o test.o && ./test.o
exit 0
