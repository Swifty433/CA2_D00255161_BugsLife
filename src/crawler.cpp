//
// Created by josep on 23/04/2024.
//

#include <iostream>
#include "crawler.h"
#include "board.h"

using namespace std;

crawler::crawler(char type, int id, int x, int y, int dir, int size) : bug(type, id, x, y, dir, size) {}

void crawler::move() {
    pair<int, int>bugPos = getPosition();

    while(isWayBlocked())
    {
        dir = static_cast<direction>(1 + (rand() % 4));
    }

    switch (dir) {
        case direction::North:
            bugPos.second--;
            break;
        case direction::East:
            bugPos.first++;
            break;
        case direction::South:
            bugPos.second++;
            break;
        case direction::West:
            bugPos.first--;
            break;
    }
    setPosition(bugPos);

    getPath().push_back(bugPos);
}

