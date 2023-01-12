#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <cstring>

using namespace std;

/*
  this is the student.h file
 */

class student {
 public:
  student();

  // stores the name
  char* name;

  // sets the name
  void setName(char*);

  // returns the name
  char* getName();
};

#endif
