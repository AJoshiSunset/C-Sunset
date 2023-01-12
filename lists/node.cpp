#include <iostream>
#include <cstring>

using namespace std;

#include "node.h"

node::node() {
  nextNode = new node;
  stu = new student;
}

node::node(student* stuVal) {
  stu = stuVal;
}

node::~node() {
  delete stu;
}

node* node::getNext() {
  return nextNode;

}

void node::setNext(node* nextVal) {

  nextNode = nextVal;

}

student* node::getStudent() {
  return stu;
}
