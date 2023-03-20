#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// header file for node class, used for finding the initial postfix form

class node {
 public:
  node();

  void setNext(node*);
  
  node* next;

  void setToken(char);

  char token;

  ~node();
};
