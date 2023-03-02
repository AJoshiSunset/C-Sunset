#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/*
  right child: index * 2 + 1
  left child: index * 2
  parent: floor(index / 2)
 */

/*
  strt at 1.
  check the 2x+1. exists?
  if yes then check it again and go back ^
  if no then print it
  then go back and print the parent
  then check the 2x. exists?
  if yes then check 2x + 1 exists
  if no to above then print
  go back to parent, already printed so back another parent
  print
  check 2x. exists?
  if yes then check 2x + 1. exists?
  if yes then print
  if no then go back and print parent
  check 2x. exists? if yes check 2x +1. if no more beyond that, print
  go back and print parent
  check 2x. exists? check 2x +1. if no, then print
 */

int findRight(int index, int used)
{
  if (2 * index + 1 <= used)
    {
      index = index * 2 + 1;
    }
  return index;
}

int findLeft(int index, int used)
{
  while (index * 2 <= used)
    {
      index = index * 2;
    }
  return index;
}

int findParent(int index)
{
  index = floor(index / 2);
  if (index == 0)
    {
      index++;
    }
  return index;
}

void addDashes(int index)
{

  while (index != 1)
    {
      index = floor(index / 2);
      cout << " ";
    }
    
}

int main()
{

  int tree[100];
  //int* tree = new int[100];
  int index = 1;
  tree[index] = 100;
  int used = 1;

  while (1 == 1)
    {
      index = used;
      int response;
      cout << "1 to add, 2 to print" << endl;
      cin >> response;

      if (response == 1)
	{
	  int ans;
	  cout << "Type in the number to enter:" << endl;
	  cin >> ans;

	  index++;
	  tree[index] = ans;
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
	  cout << "Added!" << endl;
	  cout << " " << endl;
	}
      else if (response == 2)
	{
	  cout << " " << endl;
	  int printed = 0;
	  index = 1;
	  while (printed < used)
	    {
	      index = findLeft(index, used);
	      addDashes(index);
	      cout << tree[index] << endl;
	      printed++;
	      if (printed >= used)
		{
		  break;
		}
	      index = findParent(index);
	      addDashes(index);
	      cout << tree[index] << endl;
	      printed++;
	       if (printed >= used)
                {
                  break;
                }
	       if (index != findRight(index, used))
		 {
	      index = findRight(index, used);
	      addDashes(index);
	      cout << tree[index] << endl;
	      printed++;
		 
	       if (printed >= used)
                {
                  break;
                }
		 }
	      if (index != findLeft(index, used))
		{
		  continue;
		}
	      while(index != 1)
		{
		  index = findParent(index);
		}
	      //index = findParent(index);
	      //index = findParent(index);
	      /*
	      addDashes(index);
	      cout << tree[index] << endl;
	      printed++;
	       if (printed >= used)
                {
                  break;
                }
	      */
	      index = findRight(index, used);
	    }
	 
	  
	  cout << " " << endl;
	  //cout << tree[1] << endl;
	  for (int i = 1; i < used + 1; i++)
	    {
	      cout << tree[i] << endl;
	      //cout << tree[i * 2] << endl;
	      //cout << tree[i * 2 + 1] << endl;
	    }
	  
	  cout << "Used: " << used << endl;
	  cout << "Printed!" << endl;
	  cout << " " << endl;
	}
    } 

  cout << tree[index] << endl;
  
  
  return 0;
}
