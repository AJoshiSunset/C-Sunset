#include <iostream>
#include <cstring>

using namespace std;

#include "student.h"

/*
  this is the node.h file
 */

class node: public student {
 public:
  node();

  // destructor
  ~node();

  // allows the node to take in the student
  node(student*);

  // returns next node
  node* getNext();

  // stores next node
  node* nextNode;

  // sets the next node
  void setNext(node*);

  // stores the student
  student* stu;

  // returns the student
  student* getStudent();

};

