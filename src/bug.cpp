#include "bug.h"

using namespace std;

bug::~bug(){

}

bug::bug(char type, int id, int x, int y, int dir, int size):
    type(type), id(id), position(x,y), size(size), alive(true), path()
{
    this->dir = static_cast<direction>(dir);
}

char bug::getType() const {
    return type;
}

void bug::setType(char type) {
    bug::type = type;
}

int bug::getId() const {
    return id;
}

void bug::setId(int id) {
    bug::id = id;
}

const pair<int, int> &bug::getPosition() const {
    return position;
}

void bug::setPosition(const pair<int, int> &position) {
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

list<pair<int, int>> &bug::getPath(){
    return path;
}

void bug::setPath(const list<pair<int, int>> &path) {
    bug::path = path;
}

bool bug::isWayBlocked() {
    switch (dir) {
        case direction::North:
            return (position.second == 0);
        case direction::East:
            return (position.first == 9);
        case direction::South:
            return (position.second == 9);
        case direction::West:
            return (position.first == 0);
        default:
            return true;
    }
}

bug::bug(){}