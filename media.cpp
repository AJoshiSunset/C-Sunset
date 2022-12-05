using namespace std;

#include <iostream>
#include <cstring>

#include "media.h"

// media cpp for getters

media::media() {
  title = new char[50];
  year = 0;
  //break
  director = new char[50];
  artist = new char[50];
  publisher = new char[50];
}


const char* media::getMedia() {
  return "media";
}

char* media::getTitle() {
  return title;
}

int media::getYear() {
  return year;
}

//break

char* media::getDirector() {
  return director;
}

char* media::getArtist() {
  return artist;
}

char* media::getPublisher() {
  return publisher;
}

int media::getRating() {
	return 0;
}

int media::getDuration() {
	return 0;
}
