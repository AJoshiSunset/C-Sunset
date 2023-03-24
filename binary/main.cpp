#include <iostream>
#include <cstring>

using namespace std;

class node
{
  public: 
   int token;
   node * right;
   node * left;
  node (int input)
  {
    token = input;
    right = NULL;
    left = NULL;
  }
  node ()
  {
    right = NULL;
    left = NULL;
  }
};

void addNode(node* current, node* insert, node*& head) {

  if (head == NULL)
    {
      head = insert;
    }
  else if (insert->token >= current->token)
    {
      if (current->right == NULL)
	{
	  current->right = insert;
	}
      else
	{
	  addNode(current->right, insert, head);
	}
    }
  else if (insert->token < current->token)
    {
      if (current->left == NULL)
	{
	  current->left = insert;
	}
      else
	{
	  addNode(current->left, insert, head);
	}
    }
  
}

void printAll(node* current, int count) {
  count++;
  if (current != NULL)
    {
      printAll(current->right, count);
      for (int i = 0; i < count; i++)
	{
	  cout << '\t';
	}
      cout << current->token << endl;
      printAll(current->left, count);
    }
  

}

int main() {

  node* head = new node();
  head = NULL;
  
  int response;
  
  while (1 == 1)
    {
      cout << " " << endl;
  cout << "1 to Add, 2 to Print " << endl;
  cin >> response;

  if (response == 1)
    {
      cin.get();
      cout << " " << endl;
      int ans;
      cout << "Enter number: " << endl;
      cin >> ans;

      node* n = new node(ans);
      addNode(head, n, head);
      cout << "Added!" << endl;
      
    }
  else if (response == 2)
    {
      cin.get();
      cout << " " << endl;
      printAll(head, 0);
      cout << "Printed!" << endl;
    }
  
  //cout << "Head: " << head->token << endl; 


    }
}
