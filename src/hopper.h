//
// Created by josep on 23/04/2024.
//

#ifndef CA3_D00255161_BUGSLIFE_HOPPER_H
#define CA3_D00255161_BUGSLIFE_HOPPER_H

#include "bug.h"

class hopper : public bug {

private:
    int hopLength;

public:
    hopper(char type, int id, int x, int y, int dir, int size, int hopLength);

    void move() override;
    // ~hopper();
};


#endif //CA3_D00255161_BUGSLIFE_HOPPER_H
