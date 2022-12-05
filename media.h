using namespace std;

#ifndef MEDIA
#define MEDIA

#include <iostream>
#include <cstring>

// header file for media

class media {
 public:
  media();

  virtual const char* getMedia();
  
  char* getTitle();
  
  char* title;

  int getYear();
  
  int year;

  // break

  virtual char* getDirector();

  char* director;
  
  virtual char* getArtist();

  char* artist;
  
  virtual char* getPublisher();

  char* publisher;
  
  virtual int getRating();

  virtual int getDuration();

};

#endif


