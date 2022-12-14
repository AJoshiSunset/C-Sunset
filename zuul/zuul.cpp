using namespace std;

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>

#include "room.h"

/*
  north = 1
  east = 2
  south = 4
  west = 8

  jacket = 1
  car keys = 2
  high heels = 3
  ornament = 4
  food = 5
*/

void eraseFromInventory(vector<int> & i, int item) {
  for (int a = 0; a < i.size(); a++)
    {
      if (i[a] == item)
	{
	  i.erase(i.begin() + a);
	}
    }
}

char getDirections(map<int, room*> & r, int ID) {

  int dir = r[ID]->getDirection();
  bool w = false;
  bool s = false;
  bool e = false;
  bool n = false;
  char input;
  
  while (1==1) {
  dir = r[ID]->getDirection();
  w = false;
  s = false;
  e = false;
  n = false;
  input;
  
  cout << "You can go: " << endl;;
  
  if (dir - 8 >= 0)
    {
      dir -= 8;
      w = true;
      cout << "'w' to go West" << endl;
    }
  if (dir - 4 >= 0)
    {
      dir -= 4;
      s = true;
      cout << "'s' to go South" << endl;
    }
  if (dir - 2 >= 0)
    {
      dir -= 2;
      e = true;
      cout << "'e' to go East" << endl;
    }
  if (dir - 1 >= 0)
    {
      dir -= 1;
      n = true;
      cout << "'n' to go North" << endl;
    }

  cout << "Where would you like to go?" << endl;
  //cout << "'w' for west, 's', for south, 'e' for east, 'n' for north";
  cin >> input;

  if (input == 'w' && w == true)
    {
      return 'w';
    }
  else if (input == 's' && s == true)
    {
      return 's';
    }
  else if (input == 'e' && e == true)
    {
      return 'e';
    }
  else if (input == 'n' && n == true)
    {
      return 'n';
    }
  else
    {
      cout << "Invalid Input!" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
  }
}


int main() {
  /*
  vector<room*> v;
  int currentID = 17;
    
  char* tempname = new char[50];
  
  for (int i = 0; i < 16; i++)
    {
  
  room* r = new room();

  v.push_back(r);

  switch(i) {
  case 0:
    v[i]->addDirection(2);
    v[i]->addID(1);
    strcpy(tempname, "School");
    v[i]->addName(tempname);
    break;
  case 1:
    v[i]->addDirection(14);
    v[i]->addID(2);
    strcpy(tempname, "Park");
    v[i]->addName(tempname);
    break;
  case 2:
    v[i]->addDirection(8);
    v[i]->addID(3);
    strcpy(tempname, "Lake");
    v[i]->addName(tempname);
    v[i]->addItem('4');
    break;
  case 3:
    v[i]->addDirection(6);
    v[i]->addID(7);
    strcpy(tempname, "Bridge");
    v[i]->addName(tempname);
    break;
  case 4:
    v[i]->addDirection(4);
    v[i]->addID(8);
    strcpy(tempname, "Shop");
    v[i]->addName(tempname);
    v[i]->addItem('5');
    break;
  case 5:
    v[i]->addDirection(4);
    v[i]->addID(11);
    strcpy(tempname, "Garage");
    v[i]->addName(tempname);
    break;
  case 6:
    v[i]->addDirection(7);
    v[i]->addID(12);
    strcpy(tempname, "North Street");
    v[i]->addName(tempname);
    break;
  case 7:
    v[i]->addDirection(11);
    v[i]->addID(13);
    strcpy(tempname, "East Street");
    v[i]->addName(tempname);
    break;
  case 8:
    v[i]->addDirection(14);
    v[i]->addID(14);
    strcpy(tempname, "Mountain Pass Entrance");
    v[i]->addName(tempname);
    break;
  case 9:
    v[i]->addDirection(8);
    v[i]->addID(15);
    strcpy(tempname, "Mountain Pass");
    v[i]->addName(tempname);
    break;
  case 10:
    v[i]->addDirection(3);
    v[i]->addID(16);
    strcpy(tempname, "Gas Station");
    v[i]->addName(tempname);
    v[i]->addItem('1');
    break;
  case 11:
    v[i]->addDirection(13);
    v[i]->addID(17);
    strcpy(tempname, "Gas Station Entrance");
    v[i]->addName(tempname);
    break;
  case 12:
    v[i]->addDirection(1);
    v[i]->addID(19);
    strcpy(tempname, "Friend's House");
    v[i]->addName(tempname);
    break;
  case 13:
    v[i]->addDirection(2);
    v[i]->addID(21);
    strcpy(tempname, "Diner");
    v[i]->addName(tempname);
    v[i]->addItem('2');
    break;
  case 14:
    v[i]->addDirection(11);
    v[i]->addID(22);
    strcpy(tempname, "South Street");
    v[i]->addName(tempname);
    break;
  case 15:
    v[i]->addDirection(8);
    v[i]->addID(23);
    strcpy(tempname, "Parking Lot");
    v[i]->addName(tempname);
    v[i]->addItem('3');
    break;

  }

  cout << getRoom(v, currentID)->getName() << endl;
  
  while (1 == 1)
    {
      cout << getRealID(v, currentID);
      //cout << "You are at " << v[getRealID(v, currentID)]->getName() << "." << endl;
    }
  
  
    }
  //cout << v.size() << endl;


  //cout << "ID: " << v[0]->getRoomID() << endl;

  */

  int currentID = 17;
  
  char* tempname = new char[50];
  map<int, room*> r;

  r[1] = new room();
  strcpy(tempname, "School");
  r[1]->addName(tempname);
  r[1]->addDirection(2);

  r[2] = new room();
  strcpy(tempname, "Park");
  r[2]->addName(tempname);
  r[2]->addDirection(14);

  r[3] = new room();
  strcpy(tempname, "Lake");
  r[3]->addName(tempname);
  r[3]->addDirection(8);
  r[3]->addItem(40);

  r[7] = new room();
  strcpy(tempname, "Bridge");
  r[7]->addName(tempname);
  r[7]->addDirection(5);

  r[8] = new room();
  strcpy(tempname, "Shop");
  r[8]->addName(tempname);
  r[8]->addDirection(4);
  r[8]->addItem(50);

  r[11] = new room();
  strcpy(tempname, "Garage");
  r[11]->addName(tempname);
  r[11]->addDirection(4);

  r[12] = new room();
  strcpy(tempname, "North Street");
  r[12]->addName(tempname);
  r[12]->addDirection(7);

  r[13] = new room();
  strcpy(tempname, "East Street");
  r[13]->addName(tempname);
  r[13]->addDirection(11);

  r[14] = new room();
  strcpy(tempname, "Mountain Pass Entrance");
  r[14]->addName(tempname);
  r[14]->addDirection(14);

  r[15] = new room();
  strcpy(tempname, "Mountain Pass");
  r[15]->addName(tempname);
  r[15]->addDirection(8);

  r[16] = new room();
  strcpy(tempname, "Gas Station");
  r[16]->addName(tempname);
  r[16]->addDirection(3);
  r[16]->addItem(10);

  r[17] = new room();
  strcpy(tempname, "Gas Station Entrance");
  r[17]->addName(tempname);
  r[17]->addDirection(13);

  r[19] = new room();
  strcpy(tempname, "Friend's House");
  r[19]->addName(tempname);
  r[19]->addDirection(1);

  r[21] = new room();
  strcpy(tempname, "Diner");
  r[21]->addName(tempname);
  r[21]->addDirection(2);
  r[21]->addItem(20);

  r[22] = new room();
  strcpy(tempname, "South Street");
  r[22]->addName(tempname);
  r[22]->addDirection(11);

  r[23] = new room();
  strcpy(tempname, "Parking Lot");
  r[23]->addName(tempname);
  r[23]->addDirection(8);
  r[23]->addItem(30);

  char goTo;
  int input;

  vector<int> inventory;

  while (1 == 1) {

    cout << " " << endl;
  cout << "You are at " << r[currentID]->getName() << "." << endl;

  cout << "What would you like to do? '1' to view inventory, '2' to view room items, '3' to move to another room." << endl;
  cin >> input;
  
    if (input == 1)
      {
	if (inventory.size() == 0)
	  {
	    cout << "You have nothing in your inventory!" << endl;
	  }
	else
	  {
	    for (int b = 0; b < inventory.size(); b++)
	      {
		if (inventory[b] == 10)
		  {
		    cout << "'1' to drop Jacket" << endl;
		  }
		else if (inventory[b] == 20)
		  {
		    cout << "'2' to drop Car Keys." << endl;
		  }
		else if (inventory[b] == 30)
		  {
		    cout << "'3' to drop High Heels." << endl;
		  }
		else if (inventory[b] == 40)
		  {
		    cout << "'4' to drop Ornament." << endl;
		  }
		else if (inventory[b] == 50)
		  {
		    cout << "'5' to drop Food." << endl;
		  }
	      }

	    char dropans;

	    cout << "Type 'y' to drop an item." << endl;
	    cin >> dropans;

	    if (dropans == 'y')
	      {
		while (1 == 1)
		  {
		    cout << "Type the item you would like to drop," << endl;
		    int drop;
		    cin >> drop;

		    if (drop == 1)
		      {
			eraseFromInventory(inventory, 10);
			r[currentID]->removeItem(10);
			break;
		      }
		    else if (drop == 2)
		      {
			eraseFromInventory(inventory, 20);
			r[currentID]->removeItem(20);
			break;
		      }
		    else if (drop == 3)
		      {
			eraseFromInventory(inventory, 30);
			r[currentID]->removeItem(30);
			break;
		      }
		    else if (drop == 4)
		      {
			eraseFromInventory(inventory, 40);
			r[currentID]->removeItem(40);
			break;
		      }
		    else if (drop == 5)
		      {
			eraseFromInventory(inventory, 50);
			r[currentID]->removeItem(50);
			break;
		      }
		    else
		      {
			cout << "Invalid Input!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		      }
		  }
		
	      }


	    
	  }
      }
    else if (input == 2)
      {
	vector<int> rItems = r[currentID]->getItem();
	if (rItems.size() == 0)
	  {
	    cout << "There are no items in this room!" << endl;
	    
	  }
	else
	  {
	    for (int a = 0; a < rItems.size(); a++)
	      {
		if (rItems[a] == 10)
		  {
		    cout << "'1' to pick up Jacket" << endl;
		  }
		else if (rItems[a] == 20)
		  {
		    cout << "'2' to pick up Car Keys" << endl;
		  }
		else if (rItems[a] == 30)
		  {
		    cout << "'3' to pick up High Heels" << endl;
		  }
		else if (rItems[a] == 40)
		  {
		    cout << "'4' to pick up Ornament" << endl;
		  }
		else if (rItems[a] == 50)
		  {
		    cout << "'5' to pick up Food" << endl;
		  }
	      }

	    char pickans;
	    cout << "Type 'y' to pick up an item." << endl;
	    cin >> pickans;

	    if (pickans = 'y')
	      {
		int pickup;

		while (1 == 1)
		  {
		    cout << "Type the item you would like to pick up:" << endl;
		    cin >> pickup;

		if (pickup == 1)
		  {
		    inventory.push_back(10);
		    r[currentID]->removeItem(10);
		    break;
		  }
		else if (pickup == 2)
		  {
		    inventory.push_back(20);
		    r[currentID]->removeItem(20);
		    break;
		  }
		else if (pickup == 3)
		  {
		    inventory.push_back(30);
		    r[currentID]->removeItem(30);
		    break;
		  }
		else if (pickup == 4)
		  {
		    inventory.push_back(40);
		    r[currentID]->removeItem(40);
		    break;
		  }
		else if (pickup == 5)
		  {
		    inventory.push_back(50);
		    r[currentID]->removeItem(50);
		    break;
		  }
		else
		  {
		    cout << "Invalid Input!" << endl;
		    cin.clear();
		    cin.ignore(1000, '\n');
		    continue;
		  }

		
		  }
	      }

	      
	    
	  }
      }
    else if (input == 3)
      {
	cout << "ID " << currentID << endl;
	goTo = getDirections(r, currentID);

	cout << goTo << endl;
	
	if (goTo == 'w')
	  {
	    currentID--;
	  }
	else if (goTo == 's')
	  {
	    currentID += 5;
	  }
	else if (goTo == 'e')
	  {
	    currentID++;
	  }
	else if (goTo == 'n')
	  {
	    currentID -= 5;
	  }
      }
    else
      {
	cout << "Invalid Input!" << endl;
	cin.clear();
	cin.ignore(1000, '\n');

      }


   

    

  }
  
  
  
    
    
  //cout << r[3]->getName() << endl;
  //cout << r[17]->getName() << endl;


  
  return 0;
}
