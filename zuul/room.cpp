using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"

room::room() {
  //int ID = 0;
  //itemsVec = new vector<char>();
  itemsIndex = 0;
  //charItemReturn = 'q';
  direction = 0;
  name = new char[50];
}

int room::getID() {
  return ID;
}

void room::addID(int id) {
  ID = id;
}


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

void room::addName(char* nameAdded) {
  strcpy(name, nameAdded);
}

char* room::getName() {
  return name;
}
