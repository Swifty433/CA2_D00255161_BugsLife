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

            // Set color based on position for a chessboard pattern
            if ((row + column) % 2 == 0) {
                rect.setFillColor(sf::Color(161, 102, 47)); // White color
            } else {
                rect.setFillColor(sf::Color(216, 181, 137)); // Black color
            }

            rect.setOutlineColor(sf::Color::Black); // Set border color
            rect.setOutlineThickness(1); // Set border thickness
            rect.setPosition(column * 48, row * 48);
            boardSquares.push_back(rect);
        }
    }
}

const vector<vector<char>>& board::getGrid() const {
    return grid;
}

//adding a bug from file to board
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

//show the board and whats on it
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

//if there is one bug left then game over
bool board:: gameOver(vector<bug*>&vect){

    int aliveCount = vect.size();

    for(bug* bug: vect){
        if(!bug->isAlive()){
            aliveCount--;
        }
        if(aliveCount == 1){
            return true;
        }
    }
    return false;
}

//showing all cells that are not occupied and occupied
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

//move bugs by tapping function
void board::tap(vector<bug*>&vect){
    //search vector of bugs
    for(bug* bug: vect){
        //if bug is alive
        if(bug->isAlive()){
            //then move the bug
            bug->move();
        }
    }
}

//make bugs fight
void board::fightPhase(vector<bug*>& bugs) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            //setting up a vector of bugs in that speciifc cell
            vector<bug*> bugsInCell;
            pair<int, int> cell = make_pair(x, y);

            // collect bugs in the same cell
            for (bug* bug : bugs) {
                if (bug->getPosition() == cell && bug->isAlive()) {
                    bugsInCell.push_back(bug);
                }
            }

            // if there are multiple bugs in the same cell, let them fight
            if (bugsInCell.size() > 1) {
                bug* largestBug = bugsInCell[0];

                // find the largest bug in the cell
                for (size_t i = 1; i < bugsInCell.size(); ++i) {
                    if (bugsInCell[i]->getSize() > largestBug->getSize()) {
                        largestBug = bugsInCell[i];
                    }
                }

                // mark bugs in the cell as dead except for the largest one
                for (bug* bug : bugsInCell) {
                    //check if bug is not the largest one
                    if (bug != largestBug) {
                        //set the bug as DEAD *_*
                        bug->setAlive(false);
                    }
                }

                // increase the size of the largest bug by the sum of the sizes of the eaten bugs
                int eatenSizeSum = 0;
                for (bug* bug : bugsInCell) {
                    if (bug != largestBug) {
                        //the size of bug + the size of eaten
                        eatenSizeSum += bug->getSize();
                    }
                }
                //adding size to larger bug
                largestBug->setSize(largestBug->getSize() + eatenSizeSum);
            }
        }
    }
}


//https://s7.ezgif.com/
//https://opengameart.org/content/lpc-spider
void board::draw(sf::RenderWindow &window, const vector<bug*>& vect, const sf::Texture& hopperTexture, const sf::Texture& crawlerTexture, const sf::Texture& jewelTexture) {

    for (sf::RectangleShape rs : boardSquares)
    {
        window.draw(rs);
    }

    for (const bug* bug : vect)
    {
        sf::Sprite bugSprite;
        if(bug->isAlive()) {
            switch (bug->getType()) {
                case 'H':
                    bugSprite.setTexture(hopperTexture);
                    break;
                case 'C':
                    bugSprite.setTexture(crawlerTexture);
                    break;
                case 'J':
                    bugSprite.setTexture(jewelTexture);
                    break;
                default:
                    cout << "Error with draw function" << endl;
                    break;
            }
        }

        bugSprite.setPosition(bug->getPosition().second * 48, bug->getPosition().first * 48);
        window.draw(bugSprite);
    }
}