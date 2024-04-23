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
    unsigned int id;
    std::pair<int, int> position;
    direction dir;
    unsigned int size;
    bool alive;
    std::list<std::pair<int, int>> path;
    const int* boardW;
    const int* boardH;

public:

    bug(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir = north);
    bug();

    unsigned int getId() const;


    int getX() ;
    int getY() ;

    void setX(const unsigned int x);
    void setY(const unsigned int y);

    std::pair<int, int> getPos();

    std::list<std::pair<int, int>> getPath();

    direction getDir() const;
    void setDir(direction d);

    unsigned int getSize() const;
    void grow(unsigned int by);

    bool isAlive() const;
    void die();

    const std::list<std::pair<int, int>>& getPath() const;

    virtual void move() = 0;
    virtual bool changePos(int& z, int by);

    virtual void update() = 0;

    bool isWayBlocked() ;

    std::string getPosStr();

};


#endif //CA3_D00255161_BUGSLIFE_BUG_H
