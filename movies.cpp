using namespace std;

#include <iostream>
#include <cstring>

#include "movies.h"

// movies cpp with getters

movies::movies() {
  director = new char[50];
  duration = 0;
  rating = 0;
}

const char* movies::getMedia() {
  return "movie";
}

char* movies::getDirector() {
  return director;
}

int movies::getDuration() {
  return duration;
}

int movies::getRating() {
  return rating;
}
