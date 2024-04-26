//
// Created by josep on 17/04/2024.
//

#ifndef CA3_D00255161_BUGSLIFE_BOARD_H
#define CA3_D00255161_BUGSLIFE_BOARD_H

#include "bug.h"
#include <vector>

using namespace std;

class board {
protected:
    vector<vector<char>> grid;

public:
    //Constructor

    board();

    const vector<vector<char>>& getGrid() const;

    void addBugToBoard(const bug& bug);
    void displayBoard();
};




#endif //CA3_D00255161_BUGSLIFE_BOARD_H
