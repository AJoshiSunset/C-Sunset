using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

/*
  This is the .h file for the room. It has the variables and
  functions needed for the room.cpp functionality.
 */

class room {
 public:
  room();
   
  void addItem(int);

  void removeItem(int);
  
  vector<int> getItem();

  vector<int> itemsVec;

  void addDirection(int);

  int getDirection();

  int direction;
  
  void addName(char*);

  char* getName();

  char* name;
  
};
