using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"

int main() {
  vector<room*> rvec;

  room* r = new room();

  rvec.push_back(r);

  rvec[0]->addRoomID(1);

  cout << "ID: " << rvec[0]->getRoomID() << endl;

  return 0;
}
