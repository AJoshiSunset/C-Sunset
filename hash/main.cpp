#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>

#include "student.h"
#include "node.h"
#include "hash.h"

using namespace std;


/*
  Inspiration from: 
https://www.geeksforgeeks.org/c-program-hashing-chaining/
https://www.geeksforgeeks.org/convert-string-char-array-cpp/
 */

/*
  Node.cpp, Node.o, Student.cpp, & Student.h used from
  Linked Lists Part 2
 */

/*
  Name: Avanish Joshi
  Date: 2-19-2023
  Project: This is the hashtable project. It stores students
  into an array of linked lists. You can add a student, delete
  one, view the hashtable, or generate a desired number of random
  students.
 */

int main() {
  // random seed
  srand(time(0));

  // creates the "blank" student and head node
  Student* blank = new Student();
  Node* ma = new Node(blank);
  ma->setNext(NULL);

  // creates the first hashtable and gives it 100 spaces
  int hashsize = 100;
  Hash* hashtable = new Hash(hashsize, blank);

  // creates the vector the store the added students
  vector<Node*> list;
  int count = 0;
  
  int response;

  // the logic for choosing what the user will do
  while (1 == 1)
    {
      cout << " " << endl;
  cout << "1 to add, 2 to print, 3 to delete, 4 for random, 5 to quit" << endl;
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

      // inserts the student into the hashtable and vector
      hashtable->insertS(n, blank);

      list.push_back(n);
      count++;
      
      cout << "Added!" << endl;
    }
  else if (response == 2)
    {
      // code for printing the hashtable
      cout << " " << endl;
      hashtable->displayS(blank);

      // for debugging purposes
      /*
      cout << "Master: " << endl;
      for (int i = 0; i < list.size(); i++)
	{
	  if (list[i] != NULL)
	    {
	  cout << list[i]->getStudent()->getFirstName() << endl;
	    }
	}
      cout << " " << endl;
      */
      cout << "Printed!" << endl;
    }
  else if (response == 3)
    {
      // code for deleting a student
      cout << " " << endl;
      cout << "What is the id of the student you want to delete?" << endl;
      int idans;
      cin >> idans;
      bool call = false;

      // iterates through the vector to make sure there is an id match
      for (int i = 0; i < list.size(); i++)
	{
	  if (call == false)
	    {
	      if (list[i] != NULL)
		{
	  if (list[i]->getStudent()->getID() == idans)
	    {
	      call = true;
	      list[i] = NULL;
	    }
		}
	    }
	}
      
      if (call == true)
	{
	  //  calls delete in the hashtable if the id is real
	  hashtable->deleteS(idans, blank);
	  cout << "Deleted!" << endl;
	}
      else
	{
	  cout << "Nothing Deleted" << endl;
	}
      
    }
  else if (response == 4)
    {
      // code for generating random students
      cout << " " << endl;
      int iterations;
      cout << "How many students would you like to generate?" << endl;
      cin >> iterations;
      
      int num;
      int count = 0;
      string line;

      for (int i = 0; i < iterations; i++)
	{
	  Student* s = new Student();
	  
      num = rand() % 100;
      count = 0;

      ifstream First("firstnames.txt");

      // fetching a random first name
      while(getline(First, line))
	{
	  if (num == count)
	    {
	  char* firstname = new char[50];
	  strcpy(firstname, line.c_str());
	  s->setFirstName(firstname);
	    }
	  count++;
	}

      First.close();

      num = rand() % 100;
      count = 0;
      ifstream Last("lastnames.txt");

      // fetching a random last name
      while (getline(Last, line))
	{
	  if (num == count)
	    {
	      char* lastname = new char[50];
	      strcpy(lastname, line.c_str());
	      s->setLastName(lastname);
	    }
	  count++;
	}

      Last.close();

      // creating a random id
      int rid = rand() % 500000;
      s->setID(rid);

      // creating a random id
      float rgpa = float(rand())/ float(RAND_MAX/4.0);
      s->setGPA(rgpa);

      // adding the node to the vector and hashtable
      Node* n = new Node(s);
      n->setNext(NULL);
      hashtable->insertS(n, blank);
      list.push_back(n);
      
	}
      cout << "Generated!" << endl;
    }
  else if (response == 5)
    {
      // code for quitting the program
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

  
  // every time, it checks if the hashtable needs to
  // be rehashed with twice the size
  bool rehash = hashtable->checkForRehash(); 
  
  if (rehash == true)
    {
      hashsize = hashsize * 2;
      delete hashtable;
      Hash* hashtable = new Hash(hashsize, blank);
      // iterates through the vector and adds every student
      // into the hashtable
      for (int i = 0; i < list.size(); i++)
	{
	  if (list[i] != NULL)
	    {
	      hashtable->insertS(list[i], blank);
	    }
	}
      cout << "Rehashed!" << endl;
    }

    }

  
  return 0;
}
