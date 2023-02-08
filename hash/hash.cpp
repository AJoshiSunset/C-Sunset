#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

#include "hash.h"

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


Hash::Hash(int b, Node* head) {
  // creates the array
  this->bucket = b;
  table = new Node*[bucket];

  // adds the head node to each spot in the array
  for (int i = 0; i < b; i++)
    {
      // try this:
      // create a new head node and add it to every individual element
      // in the table
      table[i] = head;
    }
  
  //table = new Node[b];
  //table = new list<Node*>[bucket];
}

void Hash::insertS(Node* key, Node* head)
{
  

 int tableid = key->getStudent()->getID() % bucket;
 //cout << bucket << endl;
 //cout << tableid - 1 << endl;
 Node* n = table[tableid - 1];
  cout << "1: " << key->getStudent()->getFirstName() << endl;

 sortStudent(n, key, head);
 cout << "2: " << key->getStudent()->getFirstName() << endl;
}

void Hash::deleteS(Student* key)
{

}

void Hash::displayS(Node* head)
{
  for (int i = 0; i < bucket; i++)
    {
      Node* c = table[i];

      while (c != NULL)
	{
	  if (c == head)
	    {
	      c = c->getNext();
	      continue;
	    }
	  cout << c->getStudent()->getFirstName() << " " << c->getStudent()->getLastName() << ", " << c->getStudent()->getID() << ", " << setprecision(3) << c->getStudent()->getGPA() << " | ";
	  c = c->getNext();
	}
      cout << " " << endl;
    }
}


