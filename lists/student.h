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

  Student(char*);

  // stores the name
  char* name;
  
  // returns the name
  char* getName();
};

#endif
