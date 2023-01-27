#include <iostream>
#include <cstring>

#include "student.h"
#include "node.h"

using namespace std;

void addStudent(Node* c, Student* blank)
{
  /*
  if (c->getStudent() == blank)
    {
      c = c->getNext();
      addStudent(c, blank);
    }
  */
  char* name = new char[50];
  char* lastname = new char[50];
  Student* s = new Student();
  
  cout << "Enter fist name:" << endl;
  cin.getline(name, 50);
  s->setName(name);

  cin.clear();
  cin.ignore(1000, '\n');
  
  cout << "Enter last name:" << endl;
  cin.getline(lastname, 50);
  s->setLastName(lastname);

  int id = 0;
  cout << "Enter ID:" << endl;
  cin >> id;
  s->setID(id);

  float gpa = 0.0;
  cout << "Enter GPA:" << endl;
  cin >> gpa;
  s->setGPA(gpa);

  Node* n = new Node(s);
  n->setNext(NULL);
  Node* temp = c;
  
  while (temp->getNext() != NULL)
    {
      temp = temp->getNext();
    }
  temp->setNext(n);
    
}

void printStudent(Node* c, Student* blank)
{
  if (c != NULL)
    {
      // make sure not to print out the head
      if (c->getStudent() == blank)
	{
	  c = c->getNext();
	    printStudent(c, blank);
	    return;
	}
      cout << c->getStudent()->getName() << " " << c->getStudent()->getLastName() << ", " << c->getStudent()->getID() << ", " << c->getStudent()->getGPA() << endl;
      printStudent(c->getNext(), blank);
      /*
      //print gpa and stuff
        Node* temp = c;

	// use recursion to call the function again each time
	while (temp != NULL)
	  {
	    cout << temp->getStudent()->getName() << " " << temp->getStudent()->getLastName() << ", " << temp->getStudent()->getID() << ", " << temp->getStudent()->getGPA() << endl;
	    temp = temp->getNext();
	  }
    }
      */
    }
}

void deleteStudent(Node* c, Student* blank, int idans)
{
  if (c != NULL)
    {
      /*
      if (c->getStudent() == blank)
	{
	  c = c->getNext();
	  deleteStudent(c, blank);
	  return;
	}
      */
      int idans;

     
      
	  if (c->getNext()->getStudent()->getID() == idans)
	    {
	      c->setNext(c->getNext()->getNext());
	      c->getNext()->~Node();
	      delete c->getNext();
	      return;
	    }
	  else
	    {
	      deleteStudent(c, blank, idans);
	    }
	
    }
}

int main() {

  Student* blank = new Student();
  Node* head = new Node(blank);

  head->setNext(NULL);

  int response;

  while (1 == 1)
    {
      cout << " " << endl;
  cout << "1 to add, 2 to print, 3 to delete, 4 to quit" << endl;
  cin >> response;
  if (response == 1)
    {
      cout << " " << endl;
      addStudent(head, blank);
      cout << "Added!" << endl;
    }
  else if (response == 2)
    {
      cout << " " << endl;
      printStudent(head, blank);
      cout << "Printed!" << endl;
    }
  else if (response == 3)
    {
      cout << " " << endl;
      cout << "What is the id of the student you want to delete?" << endl;
      int idans;
      cin >> idans;
      deleteStudent(head, blank, idans);
      cout << "Deleted!" << endl;
    }
  else if (response == 4)
    {
      cout << " " << endl;
      cout << "Quit!" << endl;
      return 0;
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
