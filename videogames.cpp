using namespace std;

#include <iostream>
#include <cstring>

#include "videogames.h"

// video games cpp for getters

videogames::videogames() {
  publisher = new char[50];
  rating = 0;

}

const char* videogames::getMedia() {
  return "videogame";
}

char* videogames::getPublisher() {
  return publisher;
}

int videogames::getRating() {
  return rating;
}
