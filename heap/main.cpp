#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

/*
  right child: index * 2 + 1
  left child: index * 2
  parent: floor(index / 2)
 */

// function to print blanks for the heap
void printBlanks(int ans)
{
  if (ans == 0)
    {
      ans++;
    }
  for (int i = 0; i < ans; i++)
    {
      cout << " ";
    }
}

// funciton to find how many parents an index has
int findParents(int index)
{
  int p = 0;
  while (index > 1)
    {
      index = floor(index / 2);
      p++;
    }
  return p;
}

int main()
{

  // setting up the variables
  int tree[100];
  int index = 1;
  tree[index] = 100;
  int used = 1;

  while (1 == 1)
    {
      index = used;
      int response;
      cout << "1 to add, 2 to print, 3 to read file, 4 to delete, 5 to quit" << endl;
      cin >> response;

      if (response == 1)
	{
	  // adding a number
	  
	  if (used != 100)
	    {
	  int ans;
	  cout << "Type in the number to enter:" << endl;
	  cin >> ans;

	  // logic to put it in its proper place
	  index++;
	  tree[index] = ans;
	  int parent = floor(index / 2);
	  if (parent < 1)
	    {
	      parent = 1;
	    }
	  while (tree[index] > tree[parent])
	    {
	      int temp = tree[parent];
	      tree[parent] = tree[index];
	      tree[index] = temp;
	      index = parent;
	      parent = floor(index / 2);
	      if (parent < 1)
		{
		  parent = 1;
		}
	    }
	  used++;
	  cout << "Added!" << endl;
	  cout << " " << endl;
	    }
	  else
	    {
	      cout << "Cannot add number!" << endl;
	      cout << " " << endl;
	    }
	}
      else if (response == 2)
	{
	  // printing the heap
	  cout << " " << endl;

	  int max = 1;
	  int i = 1;
	  int parents = 0;
	  while (max < used)
	    {
	      max = 2 * max + 1;
	    }
	  max = 2 * max + 1;

	  while(i <= used)
	    {
	      parents = findParents(i);
	      
	      if (i == 1)
		{
		  // first number in the array
		  printBlanks(floor(max / 2));
		  cout << tree[i] << endl;
		}
	      else if (i * 2 > max)
		{
		  // index is in the last row
		  if (log2(i)/floor(log2(i)) == 1)
                    {
		      // first number in the row
		      cout << tree[i];
                    }
		  else if (log2(i + 1)/floor(log2(i + 1)) == 1)
		    {
		      // last number in the row
		      printBlanks(floor(max / (pow(2, parents))));
                      cout << tree[i] << endl;
		    }
                  else
                    {
		      // in between
                      printBlanks(floor(max / (pow(2, parents))));
                      cout << tree[i];
                    }

		}
	      else
		{
		  // anywhere in between
		  
		  // if log base 2 of index divided by floor of index is 1
		  if (log2(i)/floor(log2(i)) == 1)
		    {
		      // first number in the row
		      // 2 to the how many parents you have times 2
		      printBlanks(floor(max / (pow(2, parents) * 2)));
		      cout << tree[i];
		    }
		  else if (log2(i + 1)/floor(log2(i + 1)) == 1)
		    {
		      // last number in the row
		       printBlanks(floor(max / (pow(2, parents))));
		       cout << tree[i] << endl;
		    }
		  else
		    {
		      // in between
		      printBlanks(floor(max / (pow(2, parents))));
		      cout << tree[i];
		    }
		}
	      i++;
	    }

	  cout << " " << endl;
	  cout << " " << endl;
	  cout << "Array: " << endl;

	  // printing the array
	  for (int i = 1; i < used + 1; i++)
	    {
	      cout << tree[i] << endl;
	    }
	  
	  cout << "Used: " << used << endl;
	  cout << "Printed!" << endl;
	  cout << " " << endl;
	}
      else if (response == 3)
	{
	  // reading from the file
	  cout << " " << endl;
	  string line;

	  ifstream Numbers("numbers.txt");

	  while(getline(Numbers, line))
	    {
	      int num = stoi(line);
	      index = used;
	      index++;
	      tree[index] = num;
	      int parent = floor(index / 2);
	      while (tree[index] > tree[parent])
		{
		  int temp = tree[parent];
		  tree[parent] = tree[index];
		  tree[index] = temp;
		  index = parent;
		  parent = floor(index / 2);
		}
	      used++;
	    }
	  Numbers.close();

	  cout << "Read!" << endl;
	  cout << " " << endl;
	}
      else if (response == 4)
	{
	  // deleting a number
	  cout << " " << endl;
	  int delres;
	  cout << "What is the number you want to delete?" << endl;
	  cin >> delres;
	  bool exists = false;
	  int delind = 0;
	  
	  for (int i = 1; i < used; i++)
	    {
	      if (delres == tree[i])
		{
		  exists = true;
		  delind = i;
		}
	    }

	  if (exists == true)
	    {
	      while (2 * delind <= used && 2 * delind + 1 <= used)
		{
		  // comparing left and right child
		  if (tree[2 * delind] > tree[2 * delind + 1])
		    {
		      int temp2 = tree[2 * delind];
		      tree[2 * delind] = tree[delind];
		      tree[delind] = temp2;
		      delind = 2 * delind;
		    }
		  else
		    {
		      int temp3 = tree[2 * delind + 1];
		      tree[2 * delind + 1] = tree[delind];
		      tree[delind] = temp3;
		      delind = 2 * delind + 1;
		    }
		}
	      index = delind;
	      while(index < used)
		{
		  tree[index] = tree[index + 1];
		  index++;
		}
	      used--;

	      cout << "Deleted!" << endl;
	      cout << " " << endl;
	    }
	  else
	    {
	      cout << "Nothing Deleted" << endl;
	      cout << " " << endl;
	    }
	  
	}
      else if (response == 5)
	{
	  cout << "Quitting" << endl;
	  return 0;
	}
    } 

  
  
  
  return 0;
}
