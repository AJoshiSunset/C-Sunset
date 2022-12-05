using namespace std;

#include <iostream>
#include <cstring>

#include "media.h"

// file for music header

class music: public media {
 public:
  music();

  const char* getMedia();
  
  char* getArtist();

  char* artist;

  int getDuration();

  int duration;

  char* getPublisher();

  char* publisher;

};
