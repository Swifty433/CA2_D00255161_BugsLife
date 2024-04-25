#include "bug.h"

using namespace std;

bug::~bug(){

}

bug::bug(int id, int x, int y, int dir, int size):
    id(id), position(x,y), size(size), alive(true), path()
{
    this->dir = static_cast<direction>(dir);
}

int bug::getId() const {
    return id;
}

int bug::setId(int id) {
    bug::id = id;
}

const std::pair<int, int>& bug::getPosition() const {
    return position;
}

void bug::setPosition(const std::pair<int, int>& position) {
    bug::position = position;
}

direction bug::getDir() const {
    return dir;
}

void bug::setDir(direction dir) {
    bug::dir = dir;
}

int bug::getSize() const {
    return size;
}

void bug::setSize(int size) {
    bug::size = size;
}

bool bug::isAlive() const {
    return alive;
}

void bug::setAlive(bool alive) {
    bug::alive = alive;
}

bug::bug(){}
