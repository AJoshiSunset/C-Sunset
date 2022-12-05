using namespace std;

#include <iostream>
#include <cstring>

#include "music.h"

// music cpp for getters

music::music() {
  artist = new char[50];
  duration = 0;
  publisher = new char[50];
}

const char* music::getMedia() {
  return "music";
}

char* music::getArtist() {
  return artist;
}

int music::getDuration() {
  return duration;
}

char* music::getPublisher() {
  return publisher;
}
