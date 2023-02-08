#include <cstring>
#include <iostream>

using namespace std;

#include "node.h"

class Hash {
 public:
  Hash(int, Node*);

  int bucket;

  Node** table;
  //Node *table;
  //list<Node*> *table;

  void insertS(Node*, Node*);

  void deleteS(Student*);

  void displayS(Node*);

};
