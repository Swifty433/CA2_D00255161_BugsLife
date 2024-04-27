//
// Created by josep on 26/04/2024.
//
#include <iostream>
#include "jewelBug.h"
using namespace std;

jewelBug::jewelBug(char type, int id, int x, int y, int dir, int size, int hoplength) :
        bug(type, id, x, y, dir, size) {
    this-> hopLength = hopLength;
    path.push_back(position);
}

void jewelBug::move() {
    cout << "Old Pos = " << getPosition().first << "," << getPosition().second << endl;
    pair<int, int>bugPos = getPosition();

    while(isWayBlocked())
    {
        cout << "Cant go this way" << endl;
        dir = static_cast<direction>(1 + (rand() % 4));
    }

    switch (dir) {
        case direction::North:
            bugPos.second-= hopLength;
            break;
        case direction::East:
            bugPos.first+= hopLength;
            break;
        case direction::South:
            bugPos.second+= hopLength;
            break;
        case direction::West:
            bugPos.first-= hopLength;
            break;
    }

    setPosition(bugPos);

    getPath().push_back(bugPos);
}
