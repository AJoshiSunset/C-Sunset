using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

class room {
 public:
  room();
  /*
  int getID();

  int ID;

  void addID(int);
  */
  void addItem(char);

  int itemsIndex;
  
  vector<char> getItem();

  vector<char> itemsVec;

  void addDirection(int);

  int getDirection();

  int direction;
  /*
  void addName(char[]);

  char getName();
  */
};
