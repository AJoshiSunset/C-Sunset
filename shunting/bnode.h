#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// header for the binary node, used for making the binary tree

class bnode {
 public:
  bnode();

  void setNext(bnode*);
  
  bnode* next;

  void setRight(bnode*);
  
  bnode* rightbnode;

  void setLeft(bnode*);

  bnode* leftbnode;

  void setSub(bnode*);

  bnode* subbnode;

  void setToken(char);
  
  char token;

  ~bnode();
};
