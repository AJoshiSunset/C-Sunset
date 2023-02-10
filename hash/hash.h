#include <cstring>
#include <iostream>

using namespace std;

#include "node.h"

class Hash {
 public:
  Hash(int, Student*);

  int bucket;

  Node** table;
  //Node *table;
  //list<Node*> *table;

  void insertS(Node*, Student*);

  void deleteS(Node*);

  void displayS(Student*);

};
