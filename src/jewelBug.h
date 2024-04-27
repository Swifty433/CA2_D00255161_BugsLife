//
// Created by josep on 26/04/2024.
//

#ifndef CA3_D00255161_BUGSLIFE_JEWELBUG_H
#define CA3_D00255161_BUGSLIFE_JEWELBUG_H

#include "bug.h"

class jewelBug : public  bug {

private:
    int hopLength;

public:
    jewelBug(char type, int id, int x, int y, int dir, int size, int hopLength);

    void move() override;
    //~jewelBug();
};



#endif //CA3_D00255161_BUGSLIFE_JEWELBUG_H
