#include <iostream>
#include <cstring>

using namespace std;

#include "student.h"

Student::Student() {
  name = new char[50];
  lastname = new char[50];
  id = 0;
  gpa = 0.0;
}
/*
Student::Student(char* nameVal) {
  name = new char[50];
  lastname = new char[50];
  id = 0;
  gpa = 0.0;
  strcpy(name, nameVal);
}
*/

void Student::setName(char* nameval)
{
  strcpy(name, nameval);
}

char* Student::getName() {
  return name;
}

void Student::setLastName(char* lastnameval) {
  strcpy(lastname, lastnameval);
  //lastname = lastnameval;
}

char* Student::getLastName() {
  return lastname;
}

void Student::setID(int idval) {
  id = idval;
}

int Student::getID() {
  return id;
}

void Student::setGPA(float gpaval) {
  gpa = gpaval;
}

float Student::getGPA() {
  return gpa;
}
