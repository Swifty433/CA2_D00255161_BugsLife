//
// Created by josep on 23/04/2024.
//

#ifndef CA3_D00255161_BUGSLIFE_BUG_H
#define CA3_D00255161_BUGSLIFE_BUG_H

#include <utility>
#include <list>
#include "direction.h"

class bug {
protected:
    unsigned int id;                        //id of bug
    std::pair<int, int> position;           //postition of bug (x,y)
    direction dir;                          //direction bug is facing
    unsigned int size;                      //size of bug
    bool alive;                             //bug alive or deal bool
    std::list<std::pair<int, int>> path;    //List to store path of bug
    int boardWidth;                         //width of the board
    int boardHeight;                        //height of the board

public:
    //constructor
    bug(int id, int x, int y, int size, int width, int height, direction dir = direction::NORTH);
    //default constructor
    bug();

    //getters
    int getId() const;
    int getX() const;
    int getY() const;
    std::pair<int, int> getPos() const;
    std::list<std::pair<int, int>> getPath() const;
    int getSize() const;
    direction getDir() const;

    //setters
    void setX(const int x);
    void setY(const int y);
    void setDir(direction d);

    //Methods
    void grow(unsigned int by);
    bool isAlive() const;
};

#endif //CA3_D00255161_BUGSLIFE_BUG_H
