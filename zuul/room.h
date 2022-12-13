using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

class room {
 public:
  room();
  
  int getID();

  int ID;

  void addID(int);
  
  void addItem(int);

  int itemsIndex;
  
  vector<int> getItem();

  vector<int> itemsVec;

  //char charItemReturn;

  void addDirection(int);

  int getDirection();

  int direction;
  
  void addName(char*);

  char* getName();

  char* name;
  
};
