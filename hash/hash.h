#include <cstring>
#include <iostream>

using namespace std;

#include "node.h"

class Hash {
 public:
  Hash(int);

  int bucket;
  Node *table;
  //list<Node*> *table;

  void insertS(Student*);

  void deleteS(Student*);

  void displayS();

};
