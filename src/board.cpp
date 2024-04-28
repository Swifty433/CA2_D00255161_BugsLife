//
// Created by josep on 17/04/2024.
//

#include <iostream>
#include "board.h"
#include <SFML/Graphics.hpp>
#include <unistd.h>

using namespace std;

board::board() {
    grid.assign(10, vector<char>(10, '-'));
    for (int row = 0; row < 10; row++) {
        for (int column = 0; column < 10; column++) {
            sf::RectangleShape rect(sf::Vector2f(48, 48));
            rect.setFillColor(sf::Color::Green);
            rect.setPosition(column*48, row*48);
            boardSquares.push_back(rect);
        }
    }
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

void board::fightPhase(vector<bug*>& bugs) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            vector<bug*> bugsInCell;
            pair<int, int> cell = make_pair(x, y);

            // collect bugs in same cell
            for (bug* bug : bugs) {
                if (bug->getPosition() == cell && bug->isAlive()) {
                    bugsInCell.push_back(bug);
                }
            }

            // same cell bugs fight
            if (bugsInCell.size() > 1) {
                bug* largestBug = bugsInCell[0];

                // look for largest bug in cell
                for (size_t i = 1; i < bugsInCell.size(); ++i) {
                    if (bugsInCell[i]->getSize() > largestBug->getSize()) {
                        largestBug = bugsInCell[i];
                    }
                }

                // mark bugs in cell as dead except for larges
                for (bug* bug : bugsInCell) {
                    if (bug != largestBug) {
                        bug->setAlive(false);
                    }
                }

                // increase the size of biggest bug by the sum of the sizes of the bugs eaten
                int eatenSizeSum = 0;
                for (bug* bug : bugsInCell) {
                    if (bug != largestBug) {
                        eatenSizeSum += bug->getSize();
                    }
                }
                largestBug->setSize(largestBug->getSize() + eatenSizeSum);
            }
        }
    }
}

void board::draw(sf::RenderWindow &window) {
    for (sf::RectangleShape rect : boardSquares) {
        window.draw(rect);
    }
}