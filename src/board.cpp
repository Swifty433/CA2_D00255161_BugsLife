//
// Created by josep on 17/04/2024.
//

#include <iostream>
#include "board.h"

using namespace std;

board::board() {
    grid.assign(10, vector<char>(10, '-'));
}

const vector<vector<char>>*board::getGrid() const {
    return grid;
}

void board::addBugToBoard(const bug &bug) {
    pair<int, int> position = bug.getPosition();

    if(position.first >= 0 && position.first < grid.size()
    && position.second >= 0 && position.second < grid[0].size())
    {
       char  bugType = bug.getType();
       grid[position.first][position.second] = bug.getType();
    }
    else{
        cerr << "Bug Position is out of bounds!" << endl;
    }
}
