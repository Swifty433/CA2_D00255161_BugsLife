//
// Created by josep on 17/04/2024.
//

#ifndef CA3_D00255161_BUGSLIFE_BOARD_H
#define CA3_D00255161_BUGSLIFE_BOARD_H

#include "bug.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class board {
protected:
    vector<vector<char>> grid;
    vector<sf::RectangleShape> boardSquares;

public:
    //Constructor

    board();

    const vector<vector<char>>& getGrid() const;

    void addBugToBoard(const bug& bug);
    void displayBoard();

    bug *findBugByID(const vector<bug*> & vect);

    void showAllCells(const vector<bug*>& bugs) const;

    void fightPhase(vector<bug*>& vect);

    void sfmlWindow(board& board,vector<bug*>& vect);

    void draw(sf::RenderWindow &window, const vector<bug*>& vect, const sf::Texture& hopperTexture, const sf::Texture& crawlerTexture, const sf::Texture& jewelTexture);

    bool gameOver(vector<bug *> &vect);

    void tap(vector<bug *> &vect);
};




#endif //CA3_D00255161_BUGSLIFE_BOARD_H
