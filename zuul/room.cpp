using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"

room::room() {
  ID = 0;
  //itemsVec = new vector<char>();
  //charItemReturn = 'q';
  direction = 0;
  name = new char[800];
  strcpy(name, "null");
}

void room::addID(int id) {
  ID = id;
}

int room::getID() {
  return ID;
}

void room::addItem(int itemAdded) {
  itemsVec.push_back(itemAdded);
}

void room::removeItem(int itemRemoved)
{
  for (int i = 0; i < itemsVec.size(); i++)
    {
      if (itemsVec[i] == itemRemoved)
	{
	  //delete itemsVec[i];
	  itemsVec.erase(itemsVec.begin() + i);
	}
    }
}

vector<int> room::getItem() {
  return itemsVec;
}

void room::addDirection(int dirAdded) {
  direction = dirAdded;
}

int room::getDirection() {
  return direction;
}

void room::addName(char* nameAdded) {
  strcpy(name, nameAdded);
}

char* room::getName() {
  return name;
}
