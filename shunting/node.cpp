#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#include "node.h"

// cpp file for the node class, used for finding the inital postfix form

node::node() {
  next = NULL;
}

void node::setToken(char tokenInput) {
  token = tokenInput;
}

void node::setNext(node* nextInput)
{
  next = nextInput;
}

node::~node() {

}
