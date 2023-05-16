#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

/*
  Name: Avanish Joshi
  Date: 5/14/23
  Project: This is the Red-Black Tree deletion
  project. It is the same as the previous project,
  except the user can delete nodes from the tree
  now
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

// the case 5 rotation used during deletion. used for when
// the sibling is black and its children have opposite colors
void rotation3(node* n, node* p, int nLorR, node*& head)
{
  if (nLorR == 1)
    {
      // node is a left child
      node* temp = n->right;
      if (n->right->left != NULL)
	{
	  node* temp2 = n->right->left;
	  p->left = temp;
	  temp->left = n;
	  n->right = temp2;
	}
      else
	{
	  p->left = temp;
	  temp->left = n;
	  n->right = NULL;
	}
    }
  else if (nLorR == 2)
    {
      // node is a right child
      node* temp = n->left;
      if (n->left->right != NULL)
	{
	  node* temp2 = n->left->right;
	  p->right = temp;
	  temp->right = n;
	  n->left = temp2;
	}
      else
	{
	  p->right = temp;
	  temp->right = n;
	  n->left = NULL;
	}
    }
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

// the "case 0" deletion function, the simplest deletion
void delete0(node*& head, node* n, node* k, int nLorR)
{
  if (n == head)
    {
      head = k;
    }
  else
    {
      node* p = head;
      findParent(head, n, p);
  
      if (nLorR == 1)
	{
	  p->left = k;
	}
      else if (nLorR == 2)
	{
	  p->right = k;
	}
    }
  delete n;
  k->color = 'b';
}

// the case 1 deletion used for determining the head,
// called recursively on parent
void delete1(node*& head, node* n)
{
  if (n->right != NULL && n->left == NULL)
    {
      if (n->color == 'b' && n->right->color == 'b')
	{
	  if (n == head)
	    {
	      head = n->right;
	    }
	}
    }
  else if (n->right == NULL && n->left != NULL)
    {
      if (n->color == 'b' && n->left->color == 'b')
        {
          if (n == head)
            {
              head = n->left;
            }
        }

    }
}

// the mainfunction used for deleting a node
void deleteNode(node* n, node*& head)
{
  bool caseCalled = false;
  
  int nLorR = 0;
  findLorR(head, head, n, nLorR);

  node* s = head;
  findSibling(head, n, s);
  int sLorR = 0;
  if (s != NULL)
    {
      findLorR(head, head, s, sLorR);
    }
  
  node* p = head;
  findParent(head, n, p);
  int pLorR = 0;
  findLorR(head, head, p, pLorR);

  node* u = head;
  findSibling(head, p, u);
  int uLorR = 0;
  if (u != NULL)
    {
      findLorR(head, head, u, uLorR);
    }
  
  node* g = head;
  findParent(head, p, g);
  
  // n has one non leaf child
  if (n->right == NULL && n->left != NULL)
    {
      if (n->color != n->left->color)
	{
	  delete0(head, n, n->left, nLorR);
	}
      else if (n->color == 'b' && n->left->color == 'b')
	{
	  if (n == head)
	    {
	      // case 1
	      head = n->left;
	      //caseCalled = true;
	      delete n;
	      return;
	    }
	}
    }
  else if (n->right != NULL && n->left == NULL)
    {
      if (n->color != n->right->color)
        {
          delete0(head, n, n->right, nLorR);
        }
      else if (n->color == 'b' && n->right->color == 'b')
        {
          if (n == head)
            {
	      // case 1
              head = n->right;
	      //caseCalled = true;
              delete n;
            }
        }

    }

  if (s != NULL)
    {
      if (p->color == 'b')
	{
	  if (s->right == NULL || s->left == NULL)
	    {
	      if (s->color == 'r')
		{
		  // case 2: sibling is red
		  rotation2(s, p, sLorR, head);
		  s->color = 'b';
		  p->color = 'r';
		  //caseCalled = true;
		  //deleteNode(n, head);
		}
	      else if (s->color == 'b')
		{
		  // case 3: sibling is black
		  s->color = 'r';
		  //caseCalled = true;
		  delete1(head, p);
		}
	    }
	  else if (s->right->color != 'r' && s->left->color != 'r')
	    {
	       if (s->color == 'r')
                {
                  // case 2: sibling is red
                  rotation2(s, p, sLorR, head);
                  s->color = 'b';
                  p->color = 'r';
		  //caseCalled = true;
                  //deleteNode(n, head);
                }
              else if (s->color == 'b')
                {
                  // case 3: sibling is black
                  s->color = 'r';
		  //caseCalled = true;
                  delete1(head, p);
                }
	    }

	}

      // case 4: parent is red, sibling is black
      // and both of sibling's children are black
      if (p->color == 'r' && s->color == 'b')
	{
	  if (s->right != NULL && s->left != NULL)
	    {
	      if (s->right->color == 'b' && s->left->color == 'b')
		{
		  p->color = 'b';
		  s->color = 'r';
		  //caseCalled = true;
		  //deleteNode(n, head);
		}
	    }
	}

      // case 5:
      // node is right child, sibling is black, sibling's
      // left child is black and sibling's right child is red
      // OR
      // node is left child, sibling is black, sibling's
      // left child is red, and sibling's right child is black
      if (s->right != NULL && s->left != NULL)
	{
	  if (nLorR == 2 && s->color == 'b')
	    {
	      if (s->left->color == 'b' && s->right->color == 'r')
		{
		  node* temp = s->right;
		  rotation3(s, p, sLorR, head);
		  s->color = 'r';
		  temp->color = 'b';
		  //caseCalled = true;
		  //deleteNode(n, head);
		}
	    }
	  else if (nLorR == 1 && s->color == 'b')
	    {
	      if (s->left->color == 'r' && s->right->color == 'b')
		{
		  node* temp = s->left;
		  rotation3(s, p, sLorR, head);
		  s->color = 'r';
		  temp->color = 'b';
		  //caseCalled = true;
		  //deleteNode(n, head);
		}
	    }
	}

      // case 6:
      // sibling is black, node is right child, and sibling's
      // left child is red
      // OR
      // sibling is black, node is left child, and sibling's
      // right child is red
      if (s->color == 'b' && nLorR == 2)
	{
	  if (s->left != NULL)
	    {
	      if (s->left->color == 'r')
		{
		  node* temp = s->left;
		  rotation2(s, p, sLorR, head);
		  
		  if (p->color == 'r')
		    {
		      s->color = 'r';
		    }
		  else
		    {
		      s->color = 'b';
		    }
		  p->color = 'b';
		  temp->color = 'b';
		  //caseCalled = true;
		  //deleteNode(n, head);
		}
	    }
	}
      else if (s->color == 'b' && nLorR == 1)
	{
	  if (s->right != NULL)
	    {
	      if (s->right->color == 'r')
		{
		  node* temp = s->right;
		  rotation2(s, p, sLorR, head);

		  if (p->color == 'r')
                    {
                      s->color = 'r';
                    }
                  else
                    {
                      s->color = 'b';
                    }
                  p->color = 'b';
		  temp->color = 'b';
		  //caseCalled = true;
		  //deleteNode(n, head);
		}
	    }
	}
      
    }

  if (caseCalled == false)
    {
      if (nLorR == 1)
	{
	  p->left = NULL;
	}
      else if (nLorR == 2)
	{
	  p->right = NULL;
	}
      delete n;
    }
  
}

// function used to find the in order successor
void findIOS(node*& head, node* n, node*& i)
{
  bool again = true;
  while(again == true)
    {
      if (n->left != NULL)
	{
	  n = n->left;
	  again = true;
	}
      else
	{
	  i = n;
	  again = false;
	}
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

	  // find the in order successor
	  node* i = n;
	  if (n->right != NULL)
	    {
	      i = n->right;
	      findIOS(head, n->right, i);
	    }
	  int iostoken = i->token;
	  i->token = n->token;
	  n->token = iostoken;
          
	  //n = nodeSearch(head, ans);
	  deleteNode(i, head);
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



