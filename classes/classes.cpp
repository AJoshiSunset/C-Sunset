using namespace std;

#include <iostream>
#include <cstring>
#include <vector>

#include "media.h"
#include "videogames.h"
#include "movies.h"
#include "music.h"

/*
  Project: Classes
  Name: Avanish Joshi
  Date: 12-4-22
  This is a classes project. It allows the user to add, search, and delete video games,
  music, and movies. It uses multiple .cpp files to help organize the structure of
  parents and children.
 */

// this method adds media
void addMedia(vector<media*> & v)
{
  char mediaType[50];

  while (1 == 1)
    {
  
      cout << "Would you like to add a 'videogame', 'movie', or 'music'?" << endl;

      cin >> mediaType;
      //cin.get(mediaType, 50);
      //cin.get();

      cin.clear();
      cin.ignore(1000, '\n');

      // adds videogame
      if (strcmp(mediaType, "videogame") == 0)
	{
	  //vector<videogames*> vi;
	  videogames* vi = new videogames();

	  cout << "Title:" << endl;
	  cin.getline(vi->title, 49);
	  //cin >> vi->title;
	 
	  cout << "Year:" << endl;
	  //cin.getline(vi->year, 49);
	  cin >> vi->year;

	  cin.ignore();
	  cout << "Publisher:" << endl;
	  cin.getline(vi->publisher, 49);
	  //cin >> vi->publisher;

	  cout << "Rating:" << endl;
	  //cin.getline(vi->rating, 49);
	  cin >> vi->rating;

	  v.push_back(vi);
	  
	  cin.clear();
	  cin.ignore(1000, '\n');
	  break;
	  
	}
      // adds movie
      else if (strcmp(mediaType, "movie") == 0)
	{
	  //vector<movies*> mo;
	  movies* mo = new movies();
	  
	  cout << "Title:" << endl;
	  cin.getline(mo->title, 49);
	  //cin >> mo->title;

	  cout << "Year:" << endl;
	  //cin.getline(mo->year, 49);
	  cin >> mo->year;

	  cin.ignore();
	  cout << "Director:" << endl;
	  cin.getline(mo->director, 49);
	  //cin >> mo->director;

	  cout << "Duration:" << endl;
	  //cin.getline(mo->duration, 49);
	  cin >> mo->duration;

	  cin.ignore();
	  cout << "Rating:" << endl;
	  //cin.getline(mo->rating, 49);
	  cin >> mo->rating;

	  v.push_back(mo);

	  break;
	}
      // adds music
      else if (strcmp(mediaType, "music") == 0)
	{
	  //vector<music*> mu;
	  music* mu = new music();

	  cout << "Title:" << endl;
	  cin.getline(mu->title, 49);
	  //cin >> mu->title;

	  cout << "Year:" << endl;
	  //cin.getline(mu->year, 49);
	  cin >> mu->year;

	  cin.ignore();
	  cout << "Artist:" << endl;
	  cin.getline(mu->artist, 49);
	  //cin >> mu->artist;

	  cout << "Duration:" << endl;
	  //cin.getline(mu->duration, 49);
	  cin >> mu->duration;

	  cin.ignore();
	  cout << "Publisher:" << endl;
	  cin.getline(mu->publisher, 49);
	  //cin >> mu->publisher;

	  v.push_back(mu);
	  
	  break;
	} 
      else
	{
	  cout << "Invalid Input!" << endl;
	  cin.clear();
	  cin.ignore(1000, '\n');
	  continue;
	}

      break;
    }

  
  
    }
// method to print an element from the main vector
void printMedia(vector<media*> & v, int k) {
  //cout << v[k]->getMedia() << ", " << v[k]->getTitle() << ", " << v[k]->getYear() << endl;

  cout << "Title: " << v[k]->getTitle() << endl;
  cout << "Year: " << v[k]->getYear() << endl;

  // print certain elements depending on media type
  if (strcmp(v[k]->getMedia(), "videogame") == 0)
    {
      cout << "Publisher: " << v[k]->getPublisher() << endl;
      cout << "Rating: " << v[k]->getRating() << endl;
    }
  else if (strcmp(v[k]->getMedia(), "movie") == 0)
    {
      cout << "Director: " << v[k]->getDirector() << endl;
      cout << "Duration: " << v[k]->getDuration() << endl;
      cout << "Rating: " << v[k]->getRating() << endl;
    }
  else
    {
      cout << "Artist: " << v[k]->getArtist() << endl;
      cout << "Duration: " << v[k]->getDuration() << endl;
      cout << "Publisher: " << v[k]->getPublisher() << endl;
    }
  cout << " " << endl;
}

// method for searching media
void searchMedia(vector<media*> & v) {

  char TorY[50];

  // code for title or year
  while (1 == 1) {
  cout << "Search by 'title' or 'year'?" << endl;

  cin.get(TorY, 50);
  cin.get();

  if (!(strcmp(TorY, "title") == 0 || strcmp(TorY, "year") == 0))
    {
      cout << "Invalid input!" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
  break;

    }
  
  char input[50];

  cout << "What is the " << TorY << "?" << endl;

  cin.get(input, 50);
  cin.get();

  bool nothingFound = true;

  // searches through and prints the appropriate elements
  for (int i = 0; i < v.size(); i++)
    {
      if (strcmp(TorY, "title") == 0) {
	if (strcmp(v[i]->title, input) == 0) {
	  printMedia(v, i);
	  nothingFound = false;
	}

      }
      else {
	if (v[i]->year == atoi(input)) {
	  printMedia(v, i);
	  nothingFound = false;
	}

      }
      
      
    }

  if (nothingFound == true)
    {
      cout << "Nothing found!" << endl;
    }
  
}

// method for deleting media
void deleteMedia(vector<media*> & v) {

  char TorY[50];

  while (1 == 1) {
    // code for deciding title or year
  cout << "Would you like to delete by 'title' or 'year'?" << endl;
  cin.get (TorY, 50);
  cin.get();

  if (!(strcmp(TorY, "title") == 0 || strcmp(TorY, "year") == 0)) {
    cout << "Invalid Input!" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    continue;
  }
  break;
  
  }

  char input[50];
  char confirm;
  
  cout << "What is the " << TorY << " to delete?" << endl;
  cin.get(input, 50);
  cin.get();

  // loop that finds the appropriate media and (maybe) deletes it
  for (int i = 0; i < v.size(); i++) {
    if (strcmp(TorY, "title") == 0)
      {
	if (strcmp(v[i]->getTitle(), input) == 0)
	  {
	    while (1 == 1) {
	    cout << "Do you want to delete " << v[i]->getTitle() << "? ('y' or 'n')" << endl;
	    cin >> confirm;

	    if (!(confirm == 'y' || confirm == 'n'))
	      {
		cout << "Invalid Input!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		continue;
	      }
	    break;
	    }

	    if (confirm == 'y')
	      {
		delete v[i];
		v.erase(v.begin() + i);
	      }
	  }
      }
    else
      {
	if (v[i]->year == atoi(input))
	  {
	    while (1 == 1)
	      {
		cout << "Do you want to delete " << v[i]->getTitle() << "? ('y' or 'n')" << endl;
		cin >> confirm;

		if (!(confirm == 'y' || confirm == 'n'))
		  {
		    cout << "Invalid input!" << endl;
		    cin.clear();
		    cin.ignore(1000, '\n');
		    continue;
		  }
		break;
	      }
	    if (confirm == 'y')
	      {
		delete v[i];
		v.erase(v.begin() + i);
	      }
	  }
      }
  }

  
}

// main method for choosing which function to call
int main() {

  vector<media*> vec;
  char input[50];

  while (1 == 1) {
    
    cout << "Would you like to 'add', 'search', 'delete', or 'quit'?" << endl;

    cin.get(input, 50);
    cin.get();

    
    if (strcmp(input, "add") == 0)
      {
	// adds media
	addMedia(vec);
	continue;
      }
    else if (strcmp(input, "search") == 0)
      {
	// searchs for media
	searchMedia(vec);
	continue;
      }
    else if (strcmp(input, "delete") == 0)
      {
	// deletes media
	deleteMedia(vec);
	continue;
      }
    else if (strcmp(input, "quit") == 0)
      {
	// quits the program
	break;
      }
    else
      {
	cout << "Invalid input!" << endl;
	cin.clear();
	cin.ignore(1000, '\n');
	continue;
      }

    }
  
  
  
  /*
  media* m = new media();

  cin >> m->title;

  vec.push_back(m);
  
  cout << vec[0]->title << endl;
  */
  
  return 0;
}
