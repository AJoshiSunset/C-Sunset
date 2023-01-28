#include <iostream>
#include <cstring>

#include "student.h"
#include "node.h"

using namespace std;

void addStudent(Node* c, Student* blank)
{

  if (c->getNext() == NULL)
    {
      char* firstname = new char[50];
      char* lastname = new char[50];
      Student* s = new Student();

      cin.clear();
      cin.ignore(1000, '\n');
      
      cout << "Enter fist name:" << endl;
      cin.getline(firstname, 50);
      s->setFirstName(firstname);
  
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
      c->setNext(n);
      sortStudent(c, blank);
      return;
    }
  else
    {
      addStudent(c->getNext(), blank);
      return;
    }
}

void sortStudent(Node* c, Student* blank)
{
  if (c != NULL)
    {
      /*
      if (c->getStudent() == blank)
	{
	  sortStudent(c->getNext(), blank);
	}
      */
      if (c->getNext()->getStudent()->getID() > c->getNext()->getNext()->getStudent()->getID())
	{
	  Node* temp = c->getNext();
	  c->setNext(c->getNext()->getNext());
	  c->getNext()->setNext(temp);
	}
      sortStudent(c->getNext(), blank);
      return;
    }
}

void printStudent(Node* c, Student* blank)
{
  if (c != NULL)
    {
      // make sure not to print out the head
      if (c->getStudent() == blank)
	{
	  printStudent(c->getNext(), blank);
	    return;
	}
      cout << c->getStudent()->getFirstName() << " " << c->getStudent()->getLastName() << ", " << c->getStudent()->getID() << ", " << c->getStudent()->getGPA() << endl;
      printStudent(c->getNext(), blank);
      
    }
}

void deleteStudent(Node* c, Student* blank, int idans)
{
  if (c != NULL)
    {   
      
	  if (c->getNext()->getStudent()->getID() == idans)
	    {
	      Node* temp = c->getNext();
	      c->setNext(c->getNext()->getNext());
	      temp->~Node();
	      delete temp;
	      return;
	    }
	  else
	    {
	      deleteStudent(c->getNext(), blank, idans);
	    }
	
    }
  else
    {
  cout << "Not a valid id!" << endl;
  return;
    }
}

void averageStudent(Node* c, Student* blank, float amount, int count)
{
  if (c != NULL)
    {
      if (c->getStudent() == blank)
	{
	  c = c->getNext();
	  averageStudent(c, blank, amount, count);
	  return;
	}
      amount += c->getStudent()->getGPA();
      count++;
      averageStudent(c->getNext(), blank, amount, count);
      return;
    }
  // print average
  if (!count == 0)
    {
      cout << "Average GPA: " << amount/count << endl;
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
  cout << "1 to add, 2 to print, 3 to delete, 4 to average, 5 to quit" << endl;
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
      averageStudent(head, blank, 0.0, 0);
    }
  else if (response == 5)
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
  
  return 0;
}
