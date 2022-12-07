using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"

room::room() {
  //int ID = 0;
  vector<char> itemsVec;
  int itemsIndex = 0;
  char charItemReturn = 'q';
  int direction = 0;
}
/*
int room::getID() {
  return ID;
}

void room::addID(int id) {
  ID = id;
}
*/

void room::addItem(char itemAdded) {
  itemsVec[itemsIndex] = itemAdded;
  itemsIndex++;
}

vector<char> room::getItem() {
  return itemsVec;
}

void room::addDirection(int dirAdded) {
  direction = dirAdded;
}
