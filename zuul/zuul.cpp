using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"

/*
  north = 1
  east = 2
  south = 4
  west = 8

 */

int getRealID(vector<room*>& v, int ID) {
  for (int i = 0; i < 16; i++) {
    cout << i << endl;
    if (v[i]->getID() == ID) {
      cout << i << endl;
      return i;
      }
  }
  return 0;
}

int main() {
  vector<room*> v;
  int currentID = 17;

  char* tempname = new char[50];
  
  for (int i = 0; i < 16; i++)
    {
  
  room* r = new room();

  v.push_back(r);

  switch(i) {
  case 0:
    v[i]->addDirection(2);
    v[i]->addID(1);
    strcpy(tempname, "School");
    v[i]->addName(tempname);
    break;
  case 1:
    v[i]->addDirection(14);
    v[i]->addID(2);
    strcpy(tempname, "Park");
    v[i]->addName(tempname);
    break;
  case 2:
    v[i]->addDirection(8);
    v[i]->addID(3);
    strcpy(tempname, "Lake");
    v[i]->addName(tempname);
    v[i]->addItem('o');
    break;
  case 3:
    v[i]->addDirection(6);
    v[i]->addID(7);
    strcpy(tempname, "Bridge");
    v[i]->addName(tempname);
    break;
  case 4:
    v[i]->addDirection(4);
    v[i]->addID(8);
    strcpy(tempname, "Shop");
    v[i]->addName(tempname);
    v[i]->addItem('f');
    break;
  case 5:
    v[i]->addDirection(4);
    v[i]->addID(11);
    strcpy(tempname, "Garage");
    v[i]->addName(tempname);
    break;
  case 6:
    v[i]->addDirection(7);
    v[i]->addID(12);
    strcpy(tempname, "North Street");
    v[i]->addName(tempname);
    break;
  case 7:
    v[i]->addDirection(11);
    v[i]->addID(13);
    strcpy(tempname, "East Street");
    v[i]->addName(tempname);
    break;
  case 8:
    v[i]->addDirection(14);
    v[i]->addID(14);
    strcpy(tempname, "Mountain Pass Entrance");
    v[i]->addName(tempname);
    break;
  case 9:
    v[i]->addDirection(8);
    v[i]->addID(15);
    strcpy(tempname, "Mountain Pass");
    v[i]->addName(tempname);
    break;
  case 10:
    v[i]->addDirection(3);
    v[i]->addID(16);
    strcpy(tempname, "Gas Station");
    v[i]->addName(tempname);
    v[i]->addItem('j');
    break;
  case 11:
    v[i]->addDirection(13);
    v[i]->addID(17);
    strcpy(tempname, "Gas Station Entrance");
    v[i]->addName(tempname);
    break;
  case 12:
    v[i]->addDirection(1);
    v[i]->addID(19);
    strcpy(tempname, "Friend's House");
    v[i]->addName(tempname);
    break;
  case 13:
    v[i]->addDirection(2);
    v[i]->addID(21);
    strcpy(tempname, "Diner");
    v[i]->addName(tempname);
    v[i]->addItem('c');
    break;
  case 14:
    v[i]->addDirection(11);
    v[i]->addID(22);
    strcpy(tempname, "South Street");
    v[i]->addName(tempname);
    break;
  case 15:
    v[i]->addDirection(8);
    v[i]->addID(23);
    strcpy(tempname, "Parking Lot");
    v[i]->addName(tempname);
    v[i]->addItem('h');
    break;

  }

  cout << getRealID(v, currentID);
  /*
  while (1 == 1)
    {
      cout << getRealID(v, currentID);
      //cout << "You are at " << v[getRealID(v, currentID)]->getName() << "." << endl;
    }
  */
  
    }
  cout << v.size() << endl;


  //cout << "ID: " << v[0]->getRoomID() << endl;

  return 0;
}
