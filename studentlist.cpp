using namespace std;

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

/*
  Name: Avanish Joshi
  Date: 11-1-22
  Project: This is a student list project in c++. It
  allows the user to add, print, and delete students.
  Each student has a first & last name, id, and gpa.

 */

// the struct that holds the variables for the student
struct student {

  char firstname[50];
  char lastname[50];
  int id = 0;
  float gpa = 0.0;
};

// this method adds the student
void addStudent(vector<student*> & v)
{
  int id;
  float gpa;

  // creation of new student
  student* s = new student();

  // add first name
  cout << "First name:" << endl;
  cin >> s->firstname;

  // add last name
  cout << "Last name:" << endl;
  cin >> s->lastname;

  // add id
  bool repeat = true;
  while (repeat == true) {
    repeat = false;
    cout << "ID:" << endl;
    cin >> id;
    // checks if the input is a number
    if (!cin) {
      cout << "Invalid Input!" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      repeat = true;
    }
    // checks that no one else has the id
    for (int i = 0; i < v.size(); i++) {
      if (id == v[i]->id) {
	cout << "ID in use!" << endl;
	repeat = true;
      }      
    }
    if (repeat == true) {
      continue;
    }
    else {
      // adds id to the student
      s->id = id;
      break;
    }
  }

  // add gpa
  while (1 == 1) {
  cout << "GPA:" << endl;
  cin >> gpa;
  // checks that the input is a number
  if (!cin) {
    cout << "Invalid Input!" << endl;
    cin.clear();
    cin.ignore(1000,'\n');
    continue;
  }
  // checks that the input is in range
  if (gpa < 0.0 || gpa > 5.0) {
    cout << "Can't go over 5.0 or under 0.0!" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    continue;
  }
  // adds input
  s->gpa = gpa;
  break;
  }

  cin.ignore(1000,'\n');
  // adds to vector
  v.push_back(s);
}

// method to print students
void printStudent(vector<student*> & v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i]->firstname << " " << v[i]->lastname << ", " << v[i]->id << ", " << setprecision(3) << v[i]->gpa << endl;
  }
}

// method to delete a student
void deleteStudent(vector<student*> & v) {
  int id;
  while (1 == 1) {
  cout << "ID of student to delete: " << endl;
  cin >> id;
  // checks that the input is a number
  if (!cin) {
    cout << "Invalid Input!" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    continue;
    }
  break;
  }
  cin.ignore(1000, '\n');
  // finds the student and deletes
  for (int i = 0; i < v.size(); i++) {
    if (v[i]->id == id) {
      delete v[i];
      v.erase(v.begin() + i);
    }
  }
}

// main method
int main() {

  // sets up variables and the main vector
  vector<student*> vec;
  char response[30];
  bool quit = false;

  // main loop which takes care of replay function
  while (1 == 1) {

    while (1 == 1) {

  cout << "'add' to add a student, 'print' to print them, 'delete' to delete, 'quit' to exit" << endl;
  cin.get(response, 30);
  cin.get();

  
  if (strcmp(response, "add") == 0) {
      // calls addStudent 
      cout << " " << endl;
      cout << "Adding student..." << endl;
      addStudent(vec);
      cout << " " << endl;
      break;
  } else if (strcmp(response, "print") == 0) {
      // calls printStudent
      cout << " " << endl;
      cout << "Printing students..." << endl;
      printStudent(vec);
      cout << " " << endl;
      break;
  } else if (strcmp(response, "delete") == 0) {
      // calls deleteStudent
      cout << " " << endl;
      cout << "Deleting student..." << endl;
      deleteStudent(vec);
      cout << " " << endl;
      break;
  } else if (strcmp(response, "quit") == 0) {
      // quit program
      cout << "Quitting..." << endl;
      quit = true;
      break;
  } else {
    // bad input
    cout << "Invalid Input!" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    continue;
  }

    }

    // quits the program
  if (quit == true) { 
    break;
  }
  
  }
  
  return 0;
}
