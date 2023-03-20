#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#include "bnode.h"

// cpp for the binary node class, used for constructing the binary tree

bnode::bnode() {
  next = NULL;
}

void bnode::setNext(bnode* nextInput) {
  next = nextInput;
}

void bnode::setRight(bnode* rightInput) {
  rightbnode = rightInput;
}

void bnode::setLeft(bnode* leftInput) {
  leftbnode = leftInput;
}

void bnode::setSub(bnode* subInput) {
  subbnode = subInput;
}

void bnode::setToken(char tokenInput)
{
  token = tokenInput;
}

bnode::~bnode() {

}
