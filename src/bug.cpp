#include "bug.h"

// Constructor
bug::bug(int id, int x, int y, int size, int width, int height, direction dir)
        : id(id), position(x, y), dir(dir), size(size % 20), alive(true), boardWidth(width), boardHeight(height) {}

// Default constructor
bug::bug() : id(0), position(0, 0), dir(direction::NORTH), size(0), alive(false), boardWidth(0), boardHeight(0) {}

// Getters
int bug::getId() const {
    return id;
}

int bug::getX() const {
    return position.first;
}

int bug::getY() const {
    return position.second;
}

std::pair<int, int> bug::getPos() const {
    return position;
}

std::list<std::pair<int, int>> bug::getPath() const {
    return path;
}

int bug::getSize() const {
    return size;
}

direction bug::getDir() const {
    return dir;
}

// Setters
void bug::setX(const int x) {
    position.first = x;
}

void bug::setY(const int y) {
    position.second = y;
}

void bug::setDir(direction d) {
    dir = d;
}

// Methods
void bug::grow(unsigned int by) {
    size += by;
}

bool bug::isAlive() const {
    return alive;
}
