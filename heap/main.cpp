#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/*
  right child: index * 2 + 1
  left child: index * 2
  parent: floor(index / 2)
 */

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
