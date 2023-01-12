#include <iostream>
#include <cstring>

using namespace std;

#include "node.h"
#include "student.h"

int main() {
  /*
    creates a student and assigns a name
   */
  student* s = new student();
  char* c = new char[50];
  cout << "type tim" << endl;
  cin.get(c, 50);
  s->setName(c);

  cin.clear();
  cin.ignore(1000, '\n');

  // assigns the student to a new node
  node* n = new node(s);

  /*
    creates another student and assigns a name
   */
  student* w = new student();
  cout << "type bob" << endl;
  cin.get(c, 50);
  w->setName(c);

  /*
     creates a new node, assigns the student,
     and sets it as the next of the previous node
  */
  node* l = new node(w);
  n->setNext(l);

  // node l:
  cout << "l: " << l << endl;
  // the next of node n:
  cout << "n's next: " << n->getNext() << endl;
  // the name of the student of the next of node n:
  cout << "n's next's student: " << n->getNext()->getStudent()->getName() << endl;
  // the name of l's student:
  cout << "l's student:" << l->getStudent()->getName() << endl;

  // calls the destructor on l
  l->~node();
  cout << "destroyed!" << endl;

  // prints out for verification
  cout << "l: " << l << endl;
  cout << "n's next's student: " << n->getNext()->getStudent()->getName() << endl;
  cout << "l's student: " << l->getStudent()->getName() << endl;
  
  return 0;
}
