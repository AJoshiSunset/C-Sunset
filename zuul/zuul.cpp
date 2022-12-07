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

int main() {
  vector<room*> v;
  int currentRoom = 0;
  
  for (int i = 0; i < 16; i++)
    {
  
  room* r = new room();

  v.push_back(r);

  switch(i) {
  case 0:
    v[i]->addDirection(13);
    break;
  case 1:
    v[i]->addDirection(3);
    break;
  case 2:
    v[i]->addDirection(4);
    break;
  case 3:
    v[i]->addDirection(11);
    break;
  case 4:
    v[i]->addDirection(2);
    break;
  case 5:
    v[i]->addDirection(8);
    break;
  case 6:
    v[i]->addDirection(7);
    break;
  case 7:
    v[i]->addDirection(5);
    break;
  case 8:
    v[i]->addDirection(14);
    break;
  case 9:
    v[i]->addDirection(8);
    break;
  case 10:
    v[i]->addDirection(2);
    break;
  case 11:
    v[i]->addDirection(11);
    break;
  case 12:
    v[i]->addDirection(14);
    break;
  case 13:
    v[i]->addDirection(4);
    break;
  case 14:
    v[i]->addDirection(8);
    break;
  case 15:
    v[i]->addDirection(1);
    break;

  }

    }
  cout << v.size() << endl;


  //cout << "ID: " << v[0]->getRoomID() << endl;

  return 0;
}
