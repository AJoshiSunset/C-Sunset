#include <iostream>
#include <cstring>

#include "student.h"
#include "node.h"

using namespace std;

int main() {

  char* v = new char[50];
  strcpy(v, "tim");
  Student* s = new Student(v);

  Node* n = new Node(s);

  cout << n->getStudent()->getName() << endl;

  strcpy(v, "bob");
  Student* k = new Student(v);

  Node* l = new Node(k);
  n->setNext(l);

  cout << n->getNext()->getStudent()->getName() << endl;

  strcpy(v, "jim");
  Student* p = new Student(v);

  Node* r = new Node(p);
  l->setNext(r);
  cout << "got here" << endl;
  
  cout << l->getNext()->getStudent()->getName() << endl;
  cout << n->getNext()->getNext()->getStudent()->getName() << endl;
  

  cout << "hello" << endl;

  return 0;
}

