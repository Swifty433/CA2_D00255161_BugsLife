#include <iostream>
#include <utility>
#include "bug.h"
#include "direction.h"

bug::bug(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir) {
    this->id = id;
    this->position.first = x; this->position.second = y;
    this->size;
    this->dir = dir;
    this->alive = true; 

    this->boardW = w; this->boardH = h; // gives each bug a way of knowing the size of the board

}