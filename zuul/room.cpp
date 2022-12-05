using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"

room::room() {
  int roomID = 0;
  vector<char> itemsVec;
  int itemsIndex = 0;
  char charItemReturn = 'q';
}

int room::getRoomID() {
  return roomID;
}

void room::addRoomID(int id) {
  roomID = id;

}

void room::addItem(char itemAdded) {
  itemsVec[itemsIndex] = itemAdded;
  itemsIndex++;
}

vector<char> room::getItem() {
  return itemsVec;
}
