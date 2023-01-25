#include <iostream>
#include <cstring>

#include "student.h"
#include "node.h"

using namespace std;

void addStudent(Node* & h, Student* b)
{
  char* name = new char[50];
  Student* s = new Student();
  
  cout << "Enter fist name:" << endl;
  cin.getline(name, 50);
  s->setName(name);

  cin.clear();
  cin.ignore(1000, '\n');
  
  cout << "Enter last name:" << endl;
  cin.getline(name, 50);
  s->setLastName(name);

  int id = 0;
  cout << "Enter ID:" << endl;
  cin >> id;
  s->setID(id);

  float gpa = 0.0;
  cout << "Enter GPA:" << endl;
  cin >> gpa;
  s->setGPA(gpa);

  Node* n = new Node(s);
  Node* temp = new Node(b);
  
  temp = h;
  while (temp->getNext() != NULL)
    {
      temp = temp->getNext();
    }
  temp->setNext(n);
}

void printStudent(Node* c)
{
  if (c != NULL)
    {
      // make sure not to print out the head
      //print gpa and stuff
    }
  Node* temp = new Node(b);
  temp = h->getNext();
  while (temp != NULL)
    {
      cout << temp->getStudent()->getName() << " " << temp->getStudent()->getLastName() << ", " << temp->getStudent()->getID() << ", " << temp->getStudent()->getGPA() << endl;
      temp = temp->getNext();
    }
    }
  cout << "Printed!" << endl;
}

int main() {

  Student* blank = new Student();
  Node* head = new Node(blank);

  int response;

  while (1 == 1)
    {
      cout << " " << endl;
  cout << "1 to add, 2 to print, 3 to delete" << endl;
  cin >> response;
  if (response == 1)
    {
      cout << " " << endl;
      addStudent(head, blank);
    }
  else if (response == 2)
    {
      cout << " " << endl;
      printStudent(head, blank);
    }
  else if (response == 3)
    {

    }
  else
    {
      cout << "Invalid Input!" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }

    }
  /*
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
  */
  return 0;
}
