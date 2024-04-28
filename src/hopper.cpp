//
// Created by josep on 23/04/2024.
//

#include <iostream>
#include "hopper.h"
#include "direction.h"

using namespace std;

hopper::hopper(char type, int id, int x, int y, int dir, int size, int hopLength) :
bug(type, id, x, y, dir, size) {
    this-> hopLength = hopLength;
    path.push_back(position);
}

void hopper::move() {
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
            if(bugPos.second < 0) bugPos.second = 0;
            break;
        case direction::East:
            bugPos.first+= hopLength;
            if(bugPos.first > 9) bugPos.first = 9;
            break;
        case direction::South:
            bugPos.second+= hopLength;
            if(bugPos.second > 9) bugPos.second = 9;
            break;
        case direction::West:
            bugPos.first-= hopLength;
            if(bugPos.first < 0) bugPos.first = 0;
            break;
    }
    setPosition(bugPos);

    getPath().push_back(bugPos);
    cout << "new pos = " << getPosition().first << "," << getPosition().second << "\n"<< endl;
}


