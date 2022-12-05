using namespace std; 

#include <iostream> 
#include <cstring> 

#include "media.h"

// file for videogames header

class videogames: public media {
 public:
  videogames();

  const char* getMedia();
  
  char* getPublisher();

  char* publisher;

  int getRating();

  int rating;

};
