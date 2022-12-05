using namespace std;

#include <iostream>
#include <cstring>

#include "media.h"

// file movies header

class movies: public media {
 public:
  movies();

  const char* getMedia();
  
  char* getDirector();

  char* director;

  int getDuration();

  int duration;

  int getRating();

  int rating;

};
