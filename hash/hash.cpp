#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

#include "hash.h"

// this is the method for sorting the student within a linked list accoring
// to id
 void sortStudent(Node* c, Node* n, Node* head)
 {
  if (c->getNext() != NULL)
    {
      // if the id of the node in front of the current node is less than
      // the id of the node being added, call this function again
      if (c->getNext()->getStudent()->getID() < n->getStudent()->getID())
        {
          sortStudent(c->getNext(), n, head);
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

// hashtable constructor
Hash::Hash(int b, Student* blank) {
  // creates the array
  this->bucket = b;
  table = new Node*[bucket];

  // adds the head node to each spot in the array
  for (int i = 0; i < b; i++)
    {
      Node* head = new Node(blank);
      head->setNext(NULL);
      table[i] = head;
    }
}

// adding a student
void Hash::insertS(Node* key, Student* blank)
{
  // finds the appropriate place in the hashtable
 int tableid = key->getStudent()->getID() % bucket;
 if (tableid == 0)
   {
     tableid++;
   }
 Node* n = table[tableid - 1];
 sortStudent(n, key, n);
}

// deleting a student
void Hash::deleteS(int idans, Student* blank)
{
  // finding the right position in the hashtable
  int tableid = idans % bucket;
  Node* n = table[tableid - 1];

  // iterating through the linked list and deleting it
   while (n != NULL)
    {
      if (n->getNext()->getStudent()->getID() == idans)
        {
          Node* temp = n->getNext();
          n->setNext(n->getNext()->getNext());
          temp->~Node();
          delete temp;
          return;
        }
      n = n->getNext();
    }
  
 }

// printing the hashtable
void Hash::displayS(Student* blank)
{
  for (int i = 0; i < bucket; i++)
    {
      Node* c = table[i];

      // iterates through every element in the array
      if (c->getNext() != NULL)
	{
	  cout << i + 1 << ": " << endl;
	}
      while (c->getNext() != NULL)
	{
	  // prints the elements of the student
	  cout << c->getNext()->getStudent()->getFirstName() << endl;
	  cout << c->getNext()->getStudent()->getLastName() << endl;
	  cout << "ID: " << c->getNext()->getStudent()->getID() << endl;
	  cout << "GPA: " << setprecision(3) << c->getNext()->getStudent()->getGPA() << endl;
	  cout << " " << endl;
	  c = c->getNext();
	  
	}
      //cout << "---" << endl;
    }
  cout << "Hashtable Size: " << bucket << endl;
}

// checks if there are more than three students in a row 
bool Hash::checkForRehash()
{
  for (int i = 0; i < bucket; i++)
    {
      Node* c = table[i];
      if (c->getNext() != NULL)
	{
	  c = c->getNext();
	  if (c->getNext() != NULL)
	    {
	      c = c->getNext();
	      if (c->getNext() != NULL)
		{
		  c = c->getNext();
		  if (c->getNext() != NULL)
		    {
		      c = c->getNext();
		      if (c->getNext() == NULL)
			{
			  return true;
			} 
		    }
		}
	    }
	}
    }
  return false;
}

