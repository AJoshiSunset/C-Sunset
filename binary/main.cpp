#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

/*
  Name: Avanish Joshi
  Date: 4/9/23
  Project: This is a binary search tree. You can add
  a node, delete a node, search through the tree to
  see if a node exists, or read in numbers from a file
 */

// class of the node, making the variables
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

// function for adding a node into the tree
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

// function for printing the tree
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

// Inspiration from: Nathan W.
// function for seeing if a node exists
bool search(node* current, int val) {
  if (current == NULL)
    {
      return 0;
    }
  if (current->token == val)
    {
      return 1;
    }
  return search(current->right, val) + search(current->left, val);
}

// UNUSED
// function for finding a node and returning it
node* nodeSearch(node* current, int val) {
  if (val == current->token)
    {
      cout << "current returned" << endl;
      return current;
    }
  else if (val > current->token)
    {
      nodeSearch(current->right, val);
    }
  else if (val < current->token)
    {
      nodeSearch(current->left, val);
    }
  cout << "null returned" << endl;
  return nodeSearch(current->left, val);
  return nodeSearch(current->right, val);
    
}

// UNUSED
// function for finding the parent of a node
node* findParent(node* n, node* c) {
  if (c != NULL)
    {
      if (c->left == n || c->right == n)
	{
	  return c;
	}
      else
	{
	  findParent(n, c->left);
	  findParent(n, c->right);
	}
    }
  return findParent(n, c->left);
  return findParent(n, c->right);
  //return c;
}

// UNUSED
// function for finding if the node to be
// deleted is a left or right child
int parentLorR(node* n, node* c) {
  if (c != NULL)
    {
      if (c->left == n)
	{
	  return 1;
	}
      if (c->right == n)
	{
	  return 2;
	}
      else
	{
	  parentLorR(n, c->left);
	  parentLorR(n, c->right);
	}
    }
  //return parentLorR(n, c->left);
  //return parentLorR(n, c->right);
  return 0;
}

// function for finding the next smallest node,
// used for deletion (left once, right as much
// as possible
node* findNextSmallest(node* n) {
  if (n->right != NULL)
    {
      findNextSmallest(n->right);
    }
  else
    {
      return n;
    }
  return findNextSmallest(n->right);
}

// function for deleting a node from the tree
void deleteNode(node* n, node* & head) {
  //node* p = findParent(n, head);
  //int LorR = parentLorR(n, head);

  node* p = head;
  int LorR = 0;

  // find out who the parent is and if the node
  // to be delted is a left child (1) or right (2)
  if (n != head)
    {
      bool found = false;
      while (found == false)
	{
	  if (p->left == n || p->right == n)
	    {
	      if (p->left == n)
		{
		  LorR = 1;
		}
	      else if (p->right == n)
		{
		  LorR = 2;
		}
	      found = true;
	    }
	  else
	    {
	      if (n->token < p->token)
		{
		  p = p->left;
		}
	      else if (n->token > p->token)
		{
		  p = p->right;
		}
	    }
	}
    }
  
  if (n->left == NULL && n->right == NULL)
    {
      // if the node has no children
      if (n != head)
	{
	  if (LorR == 1)
	    {
	      p->left = NULL;
	    }
	  else if (LorR == 2)
	    {
	      p->right = NULL;
	    }
	  delete n;
	}
      else
	{
	  // deleting the head
	  head = NULL;
	}
    }
  else if (n->left != NULL && n->right == NULL)
    {
      // if the node has only a left child
      if (n == head)
	{
	  head = head->left;
	}
      else
	{
	  if (LorR == 1)
	    {
	      p->left = n->left;
	    }
	  else if (LorR == 2)
	    {
	      p->right = n->left;
	    }
	  delete n;
	}
    }
  else if (n->left == NULL && n->right != NULL)
    {
      // if the node has only a right child
      if (n == head)
	{
	  head = head->right;
	}
      else
	{
	  if (LorR == 1)
	    {
	      p->left = n->right;
	    }
	  else if (LorR == 2)
	    {
	      p->right = n->right;
	    }
	  delete n;
	}
    }
  else if (n->left != NULL && n->right != NULL)
    {
      // if the node has both children
      node* nS = findNextSmallest(n->left);
      n->token = nS->token;
      deleteNode(nS, head);
    }
}

int main() {

  node* head = new node();
  head = NULL;
  
  int response;
  
  while (1 == 1)
    {
      cout << " " << endl;
  cout << "1 to Add, 2 to Print, 3 to Search, 4 to Delete, 5 to Read from file, 6 to quit" << endl;
  cin >> response;

  if (response == 1)
    {
      // add a number to the tree
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
      // print out the tree
      cin.get();
      cout << " " << endl;
      printAll(head, 0);
      cout << "Printed!" << endl;
    }
  else if (response == 3)
    {
      // search for a number in the tree
      cin.get();
      cout << " " << endl;
      int ans;
      cout << "What is the number you want to find?" << endl;
      cin >> ans;

      if (search (head, ans) == 1)
	{
	  cout << "Yes, " << ans << " is in the tree!" << endl;
	}
      else
	{
	  cout << "No, " << ans << " is not in the tree." << endl;
	}      
    }
  else if (response == 4)
    {
      // delete a number from the tree
      cin.get();
      cout << "  " << endl;
      int ans;
      cout << "What is the number you want to delete?" << endl;
      cin >> ans;

      // check the number exists
      if (search(head, ans) == 1)
	{
	  // find the appropriate node
	  bool found = false;
	  node* n = head;
	  while (found == false)
	    {
	      if (n->token == ans)
		{
		  found = true;
		}
	      else if (ans > n->token)
		{
		  n = n->right;
		}
	      else if (ans < n->token)
		{
		  n = n->left;
		}
	    }
	  
	  //n = nodeSearch(head, ans);
	  deleteNode(n, head);
	  cout << "Deleted!" << endl;
	}
      else
	{
	  cout << "Number not present." << endl;
	}
    }
  else if (response == 5)
    {
      // read in numbers from the file
      cin.get();
      cout << " " << endl;
      string line;

      ifstream Numbers("numbers.txt");

      while(getline(Numbers, line))
	{
	  node* n = new node(stoi(line));
	  addNode(head, n, head);
	}
      Numbers.close();

      cout << "Read!" << endl;
    }
  else if (response == 6)
    {
      cout << "Quit!" << endl;
      return 0;
    }
  

    }
}


