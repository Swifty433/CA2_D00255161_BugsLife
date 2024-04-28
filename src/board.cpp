//
// Created by josep on 17/04/2024.
//

#include <iostream>
#include "board.h"

using namespace std;

board::board() {
    grid.assign(10, vector<char>(10, '-'));
}

const vector<vector<char>>& board::getGrid() const {
    return grid;
}

void board::addBugToBoard(const bug& bug)
{
    pair<int, int> position = bug.getPosition();
    if (position.first >= 0 && position.first < grid.size() && position.second >= 0 && position.second < grid[0].size())
    {
        char bugType = bug.getType();
        grid[position.first][position.second] = bug.getType();
    }
    else
    {
        cerr << "Bug position is out of bounds!" << endl;
    }
}

void board::displayBoard()
{

    for(int k = 0; k < 10; ++k)
    {
        for(int j = 0; j < 10; ++j)
        {
            cout << grid[k][j] << "  ";
        }
        cout << endl;
    }
}

void board::showAllCells(const vector<bug *> &bugs) const {
    const auto& grid = getGrid();

    int i = 0;
    for(const auto& row : grid){
        for(int j = 0; j < row.size(); j++){


            bool bugFound = false;
            for(const bug* bug : bugs){
                if(bug->getPosition() == make_pair(i,j)){
                    cout << "Bug Type: " << bug->getType() << ", ID: " << bug->getId() << " ";
                    bugFound = true;
                    break;
                }
            }
            if(!bugFound){
                cout << "No bug found";
            }
            cout << endl;
        }
        i++;
    }
}

