//
// Created by josep on 26/04/2024.
//

#include "jewelBug.h"


jewelBug::jewelBug(char type, int id, int x, int y, int dir, int size, int hoplength) :
        bug(type, id, x, y, dir, size) {
    this-> hopLength = hopLength;
    path.push_back(position);
}

void jewelBug::move() {

}