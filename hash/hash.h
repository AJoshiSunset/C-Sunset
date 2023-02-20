#include <cstring>
#include <iostream>

using namespace std;

#include "node.h"

// .h file for hash
class Hash {
 public:
  Hash(int, Student*);

  // bucket is the amount of spaces in the array
  int bucket;

  // creates the main array of the hashtable
  Node** table;

  void insertS(Node*, Student*);

  void deleteS(int, Student*);

  void displayS(Student*);

  bool checkForRehash();
};
