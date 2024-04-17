#include <iostream>
#include <list>
#include <utility>
#include "main.cpp"


class bug{
private:
    int id;
    std::pair<int, int> position;   //Co-ords on board
    Direction direction;    //direction facing
    int size;   //size of bug
    bool alive; //true or false if bug is alive or dead
    std::list<std::pair<int, int>> path;    //path of bug

public:
    bug(int _id, std::pair<int,int> _position, Direction _direction, int _size, bool _alive, list<pair<int,int>> _path) :
            id(_id), position(_position), direction(_direction), size(_size), alive(_alive), path(_path) {}

};

class crawler{

};

class hopper{

};

