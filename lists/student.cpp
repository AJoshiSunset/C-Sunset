#include <iostream>
#include <cstring>

using namespace std;

#include "student.h"

student::student() {
  name = new char[50];

}

void student::setName(char* nameVal) {
  strcpy(name, nameVal);
}

char* student::getName() {
  return name;
}
