using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

class room {
 public:
  room();

  int getRoomID();

  int roomID;

  void addRoomID(int);

  void addItem(char);

  int itemsIndex = 0;
  
  vector<char> getItem();

  vector<char> itemsVec;

};
