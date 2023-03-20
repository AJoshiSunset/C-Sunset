#include <iostream>
#include <cstring>
#include <vector>

#include "node.h"
#include "bnode.h"

/*
  Name: Avanish Joshi
  Date: 3-19-23
  Project: This is the Shunting Yard Algorithm Project.
  As an input, it takes in a mathemetical expression
  (such as 2+3-6). Then, it converts it to prefix,
  postfix, or infix form using a binary tree.
 */

using namespace std;

// function for pushing the binary node into the stack
void bpush(bnode * &head, bnode* insert) {
    if(head == NULL) {
        head = insert;
	head->setNext(NULL);
    }
    else if(head != NULL) {
	bnode* current = new bnode();
	current = head;
        while(current->next != NULL) {
            current = current->next;
        }
	current->setNext(insert);
	insert->setNext(NULL);
    }
}

// function for popping the binary node out of the stack
bnode* bpop(bnode * &head) {
    int count = 0;
    bnode* previous = new bnode();
    previous = head;
    bnode* current = new bnode;
    current = head;
    while(current->next != NULL) {
        previous = current;
        current = current->next;
        count++;
    }
    if(count == 0) {
      bnode* c = head;
        head = NULL;
    }
    
    bnode* c = current;
    previous->setNext(NULL);
    cout << endl;
    
    return c;
}

// function for pushing a node into the stack
void push(node * &head, char inputValue) {
node* insert = new node();
 insert->setToken(inputValue);
if(head == NULL) {
  head = insert;
}

else if(head != NULL) {
  node* current = new node();
    current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->setNext(insert);
    insert->setNext(NULL);
 }
}

// function for popping the node out of a stack
char pop(node * &head) {
    int count = 0;
    node* previous = new node();
    previous = head;
    node* current = new node();
    current = head;
    while(current->next != NULL) {
        previous = current;
        current = current->next;
        count++;
    }
    if(count == 0) {
        char c = head->token;
        head = NULL;
    }
    
    char c = current->token;
    previous->setNext(NULL);
    current->~node();
    delete current;
    cout << endl;
    
    return c;
}

// funciton for looking at the relevant element in the stack
char peek(node * head) {
  node* current = new node();
    current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    char c = current->token;
    return c;
}

// table for easily identifying the importance of operators
int precedent(char input) {
    if(input == '^') {
        return 3;
    }
    else if(input == '/' || input == '*') {
        return 2;
    }
    else if(input == '+' || input == '-'){
        return 1;
    }
    else {
        return -1;
    }
}

// this function takes in the original infix input from the user
// and converts it to postfix
vector<char> infixInput() {
    node* stack = new node();
    stack = NULL;
    int length;
    int addon = 0;

    vector<char> output;
    vector<char> discard;

    // takes in input
    cout << "Enter the length of the expression:" << endl;
    cin >> length;
    char userinfix[length];
    
    cout << "Enter the expression:" << endl;
    for(int i = 0; i < length; i++) {
        cin >> userinfix[i];
    }

    // determines how many parantheses there are in the input
    for (int i = 0; i < length; i++)
      {
	if (userinfix[i] == '(' || userinfix[i] == ')')
	  {
	    addon++;
	  }
      }
   
    for(int i = 0; i < length; i++) {
            if (userinfix[i] >= '0' && userinfix[i] <= '9') {
	      // if the character is a number, pushes it to output
                output.push_back(userinfix[i]);
            } 
            else if(userinfix[i] == '(') {
	      // if the character is '(', pushes to stack
                push(stack, userinfix[i]);
            }

            else if(userinfix[i] == ')') {
	      // if the character is ')', pushes the stack to output
	      // until it finds the '('
                while(peek(stack) != '(') {
                    output.push_back(pop(stack));
                }
                discard.push_back(pop(stack));
            }
	     else {
	       if (stack != NULL && peek(stack) != '(')
		 {
                while(stack != NULL && precedent(userinfix[i]) <= precedent(peek(stack))) {
		  // if the operator has lower precedance, the stack gets popped into the output
		  output.push_back(pop(stack));
                }
                push(stack, userinfix[i]);
		 }
	       else {
		 push(stack, userinfix[i]);
	       }
            }

        }
        while(stack != NULL) {
            output.push_back(pop(stack));
        }

	// prints postfix form
	cout << "Postfix: " << endl;
    for(int i = 0; i < length - addon; i++) {
      cout << output[i];
    }

    stack->~node();
    delete stack;
    
    return output;

}

// this function creates the binary tree
bnode* tree(vector<char> output) {
    bnode* bstack = NULL;
    for(int i = 0; i < output.size(); i++) {
        if(output[i] >= '0' && output[i] <= '9') {
	  // adds a number to the stack
            bnode* number = new bnode();
	    number->setToken(output[i]);
            bpush(bstack, number);
        }
        else if(output[i] == '+' || '-' || '^' || '*' || '/') {
	  // determines operator placement
            bnode* Operator = new bnode();
	    Operator->setToken(output[i]);
            Operator->setRight(bpop(bstack));
            Operator->setLeft(bpop(bstack));
            bpush(bstack, Operator);
        }
	//cout << "bstack: " << bstack->token << endl;
    }

    return bstack;
}

// Inspiration from: Nathan W.

// function for printing the prefix notation
void prefix(bnode* head) {
  if (head == NULL) {
      return;
  }
    cout << head->token;
    prefix(head->leftbnode);
    prefix(head->rightbnode);
}

// printing infix notation
void infix(bnode* head) {
  if (head == NULL){
      return;
  }
    infix(head->leftbnode);
    cout << head->token;
    infix(head->rightbnode);
}

// printing postfix notation
void postfix(bnode* head) {
  if(head == NULL) {
      return;
  }
    postfix(head->leftbnode);
    postfix(head->rightbnode);
    cout << head->token;
    }

int main() {
  vector<char> output;
  bnode* treeVal = new bnode();
  
  while (1 == 1) {
    int ans;
    cout << "1 to quit, any key to continue" << endl;
    cin >> ans;

    if (ans == 1)
      {
	return 0;
      }
    else
     {
      cin.clear();
      cin.ignore(1000, '\n');

      // taking the input and converting to postfix
      output = infixInput();
      treeVal = tree(output);

      while (1 == 1)
	{
      int response;
      cout << "1 for prefix, 2 for infix, 3 for postfix, 4 to enter another expression" << endl;
      cin >> response;

      if (response == 1)
	{
	  // printing prefix
	  prefix(treeVal);
	  cout << endl;
	  continue;
	}
      else if (response == 2)
	{
	  // printing infix
	  infix(treeVal);
	  cout << endl;
	  continue;
	}
      else if (response == 3)
	{
	  // printing postfix
	  postfix(treeVal);
	  cout << endl;
	  continue;
	}
      else if (response == 4)
	{
	  // new equation
	  treeVal->~bnode();
	  delete treeVal;
	  break;
	  
	}

	}
    }

  }
    
  
  return 0;
}
