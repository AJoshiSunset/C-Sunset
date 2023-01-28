#ifndef STUDENT
#define STUDENT


#include <iostream>
#include <cstring>

using namespace std;

/*
  this is the student.h file
 */

class Student {
 public:
  Student();

  //Student(char*);

  char* firstname;

  void setFirstName(char*);
  
  char* getFirstName();

  char* lastname;

  void setLastName(char*);

  char* getLastName();

  int id;

  void setID(int);

  int getID();

  float gpa;

  void setGPA(float);

  float getGPA();
};

#endif
