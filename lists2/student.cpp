#include <iostream>
#include <cstring>

using namespace std;

#include "student.h"

Student::Student() {
  firstname = new char[50];
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

void Student::setFirstName(char* nameinput)
{
  strcpy(firstname, nameinput);
}

char* Student::getFirstName() {
  return firstname;
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
