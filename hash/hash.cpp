#include <cstring>
#include <iostream>

using namespace std;

#include "hash.h"

Hash::Hash(int b) {
  this->bucket = b;
  table = new Node[b];
  //table = new list<Node*>[bucket];
}

void Hash::insertS(Student* key)
{
  
}

void Hash::deleteS(Student* key)
{

}

void Hash::displayS()
{

}


