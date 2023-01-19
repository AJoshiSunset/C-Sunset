#include <iostream>
#include "student.h"

using namespace std;

class Node {
  public: //make it accessible
    Node(Student*); // create new node
    Node* getNext(); // gets the next node 
    Student* getStudent(); // gets the student in that node
    void setNext(Node*); // sets up the next node for another student to be added
    ~Node(); // destroys the node

    Student* nextStudent;
    Node* nextNode;
};