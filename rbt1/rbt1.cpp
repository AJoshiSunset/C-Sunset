#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

/*
  Name: Avanish Joshi
  Date: 4/30/23
  Project: This is the Red-Black Tree insertion
  project. It uses 'red' and 'black' nodes to
  sort itself out. It is a self-balancing
  binary tree.
 */

// class of the node, making the variables
class node
{
  public: 
   int token;
  char color;
   node * right;
   node * left;
  node (int input)
  {
    token = input;
    color = 'b';
    right = NULL;
    left = NULL;
  }
  node ()
  {
    color = 'b';
    right = NULL;
    left = NULL;
  }
};

// function for adding a node into the tree
void addNode(node* current, node* insert, node*& head) {

  if (head == NULL)
    {
      insert->color = 'b';
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
      cout << current->token << current->color << endl;
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

/*

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

*/


// function for finding if a node is a left(1) or
// right(2) child
void findLorR(node*& head, node* c, node* n, int& LorR)
{
  if (n != head)
    {
      bool found = false;
      while (found == false)
	{
	  if (c->left == n)
	    {
	      LorR = 1;
	      return;
	    }
	  else if (c->right == n)
	    {
	      LorR = 2;
	      return;
	    }
	  else
	    {
	      if (n->token < c->token)
		{
		  c = c->left;
		}
	      else if (n->token >= c->token)
		{
		  c = c->right;
		}
	    }
	}
    }
}

// function for finding the parent of a node
void findParent(node*& head, node* n, node*& p)
{ 
  if (n != head)
    {
      bool found = false;
      while (found == false)
        {
          if (p->left == n || p->right == n)
            {
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
  else
    {
      p = NULL;
    }
}

// function for finding the sibling of a node
void findSibling(node*& head, node* n, node*& s)
{
  if (n != head)
    {
      bool found = false;
      while (found == false)
	{
	  if (s->left == n)
	    {
	      if (s->right == NULL)
		{
		  s = NULL;
		}
	      else
		{
		  s = s->right;
		}
	      found = true;
	    }
	  else if (s->right == n)
	    {
	      if (s->left == NULL)
		{
		  s = NULL;
		}
	      else
		{
		  s = s->left;
		}
	      found = true;
	    }
	  else
	    {
	      if (n->token < s->token)
		{
		  s = s->left;
		}
	      else if (n->token >= s->token)
		{
		  s = s->right;
		}
	    }
	}
    }
  else
    {
      s = NULL;
    }
}

// the case 5 rotation function. Used for when a red node
// and its red parent are both left or both right children.
// also called on the parent after a case 4 rotation
void rotation2(node* n, node* p, int nLorR, node*& head)
{
  int pLorR = 0;
  findLorR(head, head, p, pLorR);
  if (p != head)
    {
      // if the parent is not the head
      node* g = head;
      findParent(head, p, g);
      if (nLorR == 1)
	{
	  // if the node is a left child
	  if (n->right != NULL)
	    {
	      node* temp = n->right;
	      n->right = p;
	      if (pLorR == 2)
	    {
	      g->right = n;
	    }
	  else
	    {
	      g->left = n;
	    }
	      //g->right = n;
	      p->left = temp;
	    }
	  else
	    {
	      n->right = p;
	      if (pLorR == 2)
	    {
	      g->right = n;
	    }
	  else
	    {
	      g->left = n;
	    }
	      // g->right = n;
	      p->left = NULL;
	    }
     
	  /*
	    n->right = tp;
	    p->left = NULL;
	  */
	}
      else if (nLorR == 2)
	{
	  // if the node is a right child
	  if (n->left != NULL)
	    {
	      node* temp = n->left;
	      n->left = p;
	       if (pLorR == 2)
	    {
	      g->right = n;
	    }
	  else
	    {
	      g->left = n;
	    }
	       // g->left = n;
	      p->right = temp;
	    }
	  else
	    {
	      n->left = p;
	      
	  if (pLorR == 2)
	    {
	      g->right = n;
	    }
	  else
	    {
	      g->left = n;
	    }
	  
	  //g->left = n;
	      p->right = NULL;
	    }
	}
    }
  else
    {
      // if the parent is the head
      if (nLorR == 1)
	{
	  // if the node is a left child
	  if (n->right != NULL)
	    {
	      node* temp = n->right;
	      n->right = p;
	      p->left = temp;
	    }
	  else
	    {
	      n->right = p;
	      p->left = NULL;
	    }
	}
      else if (nLorR == 2)
	{
	  // if the node is a right child
	  if (n->left != NULL)
	    {
	      node* temp = n->left;
	      n->left = p;
	      p->right = temp;
	    }
	  else
	    {
	      n->left = p;
	      p->right = NULL;
	    }
	}
      // set head to node
      head = n;
    }
  n->color = 'b';
  p->color = 'r';
}

// the case 4 rotation function. used for when the parent is the left child
// and the child is a right child or vice versa. Used to switch their order
void rotation(node* n, node* p, node* g, int nLorR, int pLorR, node*& head)
{
  if (nLorR == 2)
    {
      // node is a right child
      if (n->left != NULL)
	{
	  node* temp = n->left;
	  g->left = n;
	  n->left = p;
	  p->right = temp;
	}
      else
	{
	  
	  g->left = n;
	  n->left = p;
	  p->right = NULL;
	}

      /*
      n->left = tp;
      g->left = NULL;
      p->right = NULL;
      g->left = tn;
      */
    }
  else if (nLorR == 1)
    {
      // node is a left child
      if (n->right != NULL)
	{
	  node* temp = n->right;
	  g->right = n;
	  n->right = p;
	  p->left = temp;
	}
      else
	{
	  g->right = n;
	  n->right = p;
	  p->left = NULL;
	}

      /*
      n->right = tp;
      g->right = NULL;
      p->left = NULL;
      g->right = tn;
      */
    }
  int nLorR2 = 0;
  findLorR(head, head, n, nLorR2);
  cout << nLorR2 << endl;
  rotation2(n, g, nLorR2, head);
}

// the function called every iteration. it finds the colors
// of a node, its parent, and its uncle. decides what to do
// based on repeat reds occuring in the tree
void parentUncle(node* n, node*& head)
{
  if (n != head)
    {
      int nLorR = 0;
      findLorR(head, head, n, nLorR);
      
      // finds the parent of node n: p
      node* p = head;
      findParent(head, n, p);
      int pLorR = 0;
      findLorR(head, head, p, pLorR);


      // finds the uncle of node n (sibling of p): u
      node* u = head;
      findSibling(head, p, u);
      int uLorR = 0;
      if (u != NULL)
	{
	  findLorR(head, head, u, uLorR);
	}
  
      // finds the grandparent of node n (parent of p): g
      node* g = head;
      findParent(head, p, g);

      // if the parent and uncle are red, switch the colors
      if (u != NULL)
	{
	  if (p->color == 'r' && u->color == 'r')
	    {
	      p->color = 'b';
	      u->color = 'b';
	      g->color = 'r';

	      // calls function on grandparent
	      parentUncle(g, head);
	    }
	}

      // if the parent is red and uncle is null
      if (p->color == 'r' && u == NULL)
	{

	  // case 4 rotation
	  if (pLorR == 1 && nLorR == 2)
	    {
              rotation(n, p, g, nLorR, pLorR, head);
	    }
	  else if (pLorR == 2 && nLorR == 1)
	    {
              rotation(n, p, g, nLorR, pLorR, head);
	    }

	  // case 5 rotation
	  if (pLorR == 1 && nLorR == 1)
	    {
	      rotation2(p, g, pLorR, head);
	    }
	  else if (pLorR == 2 && nLorR == 2)
	    {
	      rotation2(p, g, pLorR, head);
	    }
	}
      else if (p->color == 'r' && u->color == 'b')
	{
	  // if the parent is red and the uncle is black
	  
	  // case 4 rotation
	  if (pLorR == 1 && nLorR == 2)
            {
              rotation(n, p, g, nLorR, pLorR, head);
            }
          else if (pLorR == 2 && nLorR == 1)
            {
              rotation(n, p, g, nLorR, pLorR, head);
            }

	  // case 5 rotation
	  if (pLorR == 1 && nLorR == 1)
            {
              rotation2(p, g, pLorR, head);
            }
          else if (pLorR == 2 && nLorR == 2)
            {
              rotation2(p, g, pLorR, head);
            }

	}
      
    }
}

// function used to check colors for every red node
// on the tree
void callParentUncle(node* n, node*& head)
{
  if (n != NULL && n->color == 'r')
    {
      parentUncle(n, head);
    }
  if (n->left != NULL)
    {
      callParentUncle(n->left, head);
    }
  if (n->right != NULL)
    {
      callParentUncle(n->right, head);
    }
}

int main() {

  node* head = new node();
  head = NULL;
  
  int response;
  
  while (1 == 1)
    {
      cout << " " << endl;
  cout << "1 to Add, 2 to Print, 3 to Search, 5 to Read from file, 6 to quit" << endl;
  cin >> response;

  if (response == 1)
    {
      // add a number to the tree
      cin.get();
      cout << " " << endl;
      int ans;
      cout << "Enter number: " << endl;
      while (true)
	{
      cin >> ans;
      
	
      node* n = new node(ans);
      n->color = 'r';
      addNode(head, n, head);

      if (cin.peek() == '\n')
	{
	  break;
	}
	}
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
      /*
      
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

      */
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
	  n->color = 'r';
	  addNode(head, n, head);
	  callParentUncle(head, head);
	}
      Numbers.close();

      cout << "Read!" << endl;
    }
  else if (response == 6)
    {
      cout << "Quit!" << endl;
      return 0;
    }

  // checks double redness for all nodes in tree
  callParentUncle(head, head);

  // makes sure head is black
  if (head->color != 'b')
    {
      head->color = 'b';
    }

    }
}




