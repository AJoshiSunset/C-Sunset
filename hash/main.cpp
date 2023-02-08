#include <iostream>
#include <cstring>
#include <iomanip>

#include "student.h"
#include "node.h"
#include "hash.h"

using namespace std;


/*
https://www.geeksforgeeks.org/c-program-hashing-chaining/
 */

int main() {
  Student* blank = new Student();
  Node* head = new Node(blank);
  head->setNext(NULL);

  int hashsize = 100;

  Hash* hashtable = new Hash(hashsize, head);
  
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

      // allows the user to get all the values needed for setting
      // up the student
      char* firstname = new char[50];
      char* lastname = new char[50];
      Student* s = new Student();

      cin.clear();
      cin.ignore(1000, '\n');
      
      cout << "Enter first name:" << endl;
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
      
      hashtable->insertS(n, head);
      
      cout << "Added!" << endl;
    }
  else if (response == 2)
    {
      cout << " " << endl;
      hashtable->displayS(head);
      cout << "Printed!" << endl;
    }
  else if (response == 3)
    {
      cout << " " << endl;
      cout << "What is the id of the student you want to delete?" << endl;
      int idans;
      cin >> idans;
      cout << "Deleted!" << endl;
    }
  else if (response == 4)
    {
      cout << " " << endl;
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

  // call hash with node
  
  return 0;
}
