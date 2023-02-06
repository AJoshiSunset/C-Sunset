#include <iostream>
#include <cstring>
#include <iomanip>

#include "student.h"
#include "node.h"

using namespace std;

/*
  Project: Linked Lists Part 2
  Name: Avanish Joshi
  Date: 1-27-23
  This project is student list but made using nodes and linked lists.
  You can add, print, and delete students, as well as averaging all
  of the gpas. All of this is done using linked lists and nodes.
 */

// this function allows to fetch the pervious node in the linked list
// given a node
Node* getPrevious(Node* c, Student* blank, Node* p) {
  if (p->getNext() == c)
    {
      return p;
    }
  else
    {
      getPrevious(c, blank, p->getNext());
    }
  return NULL;
  
}

// this function sorts the new added node based on the value of its id
void sortStudent(Node* c, Student* blank, Node* n, Node* head)
{
  if (c->getNext() != NULL)
    {
      // if the id of the node in front of the current node is less than
      // the id of the node being added, call this function again
      if (c->getNext()->getStudent()->getID() < n->getStudent()->getID())
	{
	  sortStudent(c->getNext(), blank, n, head);
	}
      else
	{
	  // adds the node into the linked list
	  Node* temp = c->getNext();
	  c->setNext(n);
	  n->setNext(temp);
	  return;
	}
      
    }
  else
    {
      // otherwise, add the node to the end of the list
      c->setNext(n);
      n->setNext(NULL);
      return;
      
    }
}

// method to add a node
void addStudent(Node* c, Student* blank, Node* head)
{

  if (c->getNext() == NULL)
    {
      // allows the user to get all the values needed for setting
      // up the student
      char* firstname = new char[50];
      char* lastname = new char[50];
      Student* s = new Student();

      cin.clear();
      cin.ignore(1000, '\n');
      
      cout << "Enter frist name:" << endl;
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
      // calls the sort function
      sortStudent(head, blank, n, head);
      
      return;
    }
  else
    {
      addStudent(c->getNext(), blank, head);
      return;
    }
}

// this function prints all of the nodes in the linked list
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
      // prints everything in one sentence
      cout << c->getStudent()->getFirstName() << " " << c->getStudent()->getLastName() << ", " << c->getStudent()->getID() << ", " << setprecision(3) << c->getStudent()->getGPA() << endl;
      printStudent(c->getNext(), blank);
      
    }
}

// this function deletes a node
void deleteStudent(Node* c, Student* blank, int idans)
{
  if (c != NULL)
    {   
      
	  if (c->getNext()->getStudent()->getID() == idans)
	    {
	      // deletes the node and appropriately sets the next node
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

// this function takes the average of all of the gpas
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
      // if the node isn't the head node, add its gpa to the overall count
      amount += c->getStudent()->getGPA();
      count++;
      averageStudent(c->getNext(), blank, amount, count);
      return;
    }
  // eventually the average is taken and printed
  if (!count == 0)
    {
      cout << "Average GPA: " << amount/count << endl;
    }
}

// the main function with the choosing logic
int main() {

  // creating the empty head node
  Student* blank = new Student();
  Node* head = new Node(blank);

  head->setNext(NULL);

  int response;

  // the logic for choosing what the user will do
  while (1 == 1)
    {
      cout << " " << endl;
  cout << "1 to add, 2 to print, 3 to delete, 4 to average, 5 to quit" << endl;
  cin >> response;
  if (response == 1)
    {
      cout << " " << endl;
      addStudent(head, blank, head);
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
