using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"

room::room() {
  ID = 0;
  //itemsVec = new vector<char>();
  itemsIndex = 0;
  //charItemReturn = 'q';
  direction = 0;
  name = new char[50];
}

void room::addID(int id) {
  ID = id;
}

int room::getID() {
  return ID;
}

void room::addItem(int itemAdded) {
  //strcpy(itemsVec[itemsIndex], itemAdded);
  itemsVec.push_back(itemAdded);
  //itemsVec[itemsIndex] = itemAdded;
  itemsIndex++;
}

vector<int> room::getItem() {
  return itemsVec;
}

void room::addDirection(int dirAdded) {
  direction = dirAdded;
}

void room::addName(char* nameAdded) {
  strcpy(name, nameAdded);
}

char* room::getName() {
  return name;
}
