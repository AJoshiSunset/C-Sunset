using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"

/*
  This is the .cpp file for the room. It allows to add, remove,
  store, and give back items. It can also add, store, and give
  back the name. It will also add, store, and give back the
  direction.
 */

room::room() {
  direction = 0;
  name = new char[800];
  strcpy(name, "null");
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
