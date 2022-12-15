using namespace std;

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>

#include "room.h"

/*
  Name: Avanish Joshi
  Date: 12-14-22
  Project: Zuul
  This project is a game where you can go from room to room. Some rooms have items in them
  and you can pick them up to store them in your inventory. You can also drop these items
  from your inventory into the room.
 */

/*
  HOW TO WIN:
  You start at the Gas Station Entrance. You need to have the Car Keys (from the Diner),
  Ornament (from the Lake), and Food (from the Shop) in your inventory and be at the
  Mountain Pass.
 */

/*
  north = 1
  east = 2
  south = 4
  west = 8

  jacket = 10
  car keys = 20
  high heels = 30
  ornament = 40
  food = 50
*/

// this method erases an item from the inventory
void eraseFromInventory(vector<int> & i, int item) {
  for (int a = 0; a < i.size(); a++)
    {
      if (i[a] == item)
	{
	  i.erase(i.begin() + a);
	}
    }
}

// this method converts the 'directions' int to west, south, east, and north the user can understand
char getDirections(map<int, room*> & r, int ID) {
  
  while (1 == 1) {
  int dir = r[ID]->getDirection();
  bool w = false;
  bool s = false;
  bool e = false;
  bool n = false;
  char input;
  
  cout << "You can go: " << endl;;

  // these if statements decipher the directions possible
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

  // takes in input from the user
  cout << "Where would you like to go?" << endl;
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

// this method checks if the user meets the win conditions
bool checkWin(vector<int> v, int ID)
{
  int winCounter = 0;

  // checks if they have the car keys, ornament, and food
  for (int i = 0; i < v.size(); i++)
    {
      if (v[i] == 20 || v[i] == 40 || v[i] == 50)
	{
	  winCounter++;
	}
    }

  // checks that they're at the mountain pass
  if (ID == 15)
    {
      winCounter++;
    }

  if (winCounter == 4)
    {
      return true;
    }
  else
    {
      return false;
    }

}


int main() {

  int currentID = 17;
  
  char* tempname = new char[800];
  map<int, room*> r;

  // these blocks create the rooms and assigns their names, directions, and items
  
  r[1] = new room();
  strcpy(tempname, "the School. For some reason, you don't feel like staying here any longer than you need to.");
  r[1]->addName(tempname);
  r[1]->addDirection(2);

  r[2] = new room();
  strcpy(tempname, "the Park. Seeing as it's 11pm, there's barely anyone here.");
  r[2]->addName(tempname);
  r[2]->addDirection(14);

  r[3] = new room();
  strcpy(tempname, "the Lake. The sparkling stars peacefully glisten off of the calm water.");
  r[3]->addName(tempname);
  r[3]->addDirection(8);
  r[3]->addItem(40);

  r[7] = new room();
  strcpy(tempname, "the Bridge. You have a full view of the great Mountain Pass nearby.");
  r[7]->addName(tempname);
  r[7]->addDirection(5);

  r[8] = new room();
  strcpy(tempname, "your Shop. However, there's not much actual selling going on.");
  r[8]->addName(tempname);
  r[8]->addDirection(4);
  r[8]->addItem(50);

  r[11] = new room();
  strcpy(tempname, "the Garage. There's a car with its hood popped open, with tools scattered everywhere.");
  r[11]->addName(tempname);
  r[11]->addDirection(4);

  r[12] = new room();
  strcpy(tempname, "North Street. This is usually a pretty busy intersection.");
  r[12]->addName(tempname);
  r[12]->addDirection(7);

  r[13] = new room();
  strcpy(tempname, "East Street. This road leads to the Mountain Pass.");
  r[13]->addName(tempname);
  r[13]->addDirection(11);

  r[14] = new room();
  strcpy(tempname, "the Mountain Pass Entrance. The giant Mountain Pass looms over, looking unconquerable.");
  r[14]->addName(tempname);
  r[14]->addDirection(14);

  r[15] = new room();
  strcpy(tempname, "the Mountain Pass. However if you're reading this, you're not ready yet!");
  r[15]->addName(tempname);
  r[15]->addDirection(8);

  r[16] = new room();
  strcpy(tempname, "the Gas Station. You come here often to hang out with your friends.");
  r[16]->addName(tempname);
  r[16]->addDirection(3);
  r[16]->addItem(10);

  r[17] = new room();
  strcpy(tempname, "the Gas Station Entrance. It leads to your place of work.");
  r[17]->addName(tempname);
  r[17]->addDirection(13);

  r[19] = new room();
  strcpy(tempname, "your Friend's House. While you're here, you should ask him for some advice.");
  r[19]->addName(tempname);
  r[19]->addDirection(1);

  r[21] = new room();
  strcpy(tempname, "the Diner. It's bustling with people and food, even at this late hour.");
  r[21]->addName(tempname);
  r[21]->addDirection(2);
  r[21]->addItem(20);

  r[22] = new room();
  strcpy(tempname, "South Street. This is usually not a pretty busy interaction.");
  r[22]->addName(tempname);
  r[22]->addDirection(11);

  r[23] = new room();
  strcpy(tempname, "the Parking Lot. There's a big billboard facing towards South Street, and not much else.");
  r[23]->addName(tempname);
  r[23]->addDirection(8);
  r[23]->addItem(30);

  char goTo;
  int input;

  vector<int> inventory;

  // starts main functionality
  while (1 == 1) {

    cout << " " << endl;
  cout << "You are at " << r[currentID]->getName() << endl;

  cout << "What would you like to do? '1' to view inventory, '2' to view room items, '3' to move to another room, '4' to quit." << endl;
  cin >> input;
  
    if (input == 1)
      {
	// this code is related to the inventory. You can view it and drop stuff
	if (inventory.size() == 0)
	  {
	    cout << "You have nothing in your inventory!" << endl;
	  }
	else
	  {
	    // if there are items in the inventory, it will print them out and tell how to drop them
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

	    // this asks the user if they want to drop an item
	    char dropans;
	    cout << "Type 'y' to drop an item." << endl;
	    cin >> dropans;

	    if (dropans == 'y')
	      {
		// if they do, they can type the number of the item to drop
		while (1 == 1)
		  {
		    cout << "Type the item you would like to drop," << endl;
		    int drop;
		    cin >> drop;

		    if (drop >= 1 && drop <=5)
		      {
			eraseFromInventory(inventory, drop*10);
			r[currentID]->addItem(drop*10);
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
	// this code is for the room/items. You can view it and pick stuff up
	vector<int> rItems = r[currentID]->getItem();
	if (rItems.size() == 0)
	  {
	    cout << "There are no items in this room!" << endl;
	  }
	else
	  {
	    // if there are items in the room, it prints them out and tells how to pick them up
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

	    // this code asks if the user wants to pick up an item
	    char pickans;
	    cout << "Type 'y' to pick up an item." << endl;
	    cin >> pickans;

	    if (pickans == 'y')
	      {
		// if they do, they can type the number of the item to pick up
		int pickup;

		while (1 == 1)
		  {
		    cout << "Type the item you would like to pick up:" << endl;
		    cin >> pickup;

		    if (pickup >= 1 && pickup <= 5)
		      {
			inventory.push_back(pickup*10);
			r[currentID]->removeItem(pickup*10);
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
	// this code is for when you want to move to another room
	
	cout << "ID " << currentID << endl;
	goTo = getDirections(r, currentID);

	cout << goTo << endl;

	// this handles the changing of the id that allows moving
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
    else if (input == 4)
      {
	// quit the game
	return 0;
      }
    else
      {
	cout << "Invalid Input!" << endl;
	cin.clear();
	cin.ignore(1000, '\n');
      }

    // checks if the user meets the win conditions
    if (checkWin(inventory, currentID) == true)
      {
	break;
      }
    else
      {
	continue;
      }

    

  }

  // win message
  cout << "You win!" << endl;
 
  return 0;
}
