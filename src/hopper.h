//
// Created by josep on 23/04/2024.
//

#ifndef CA3_D00255161_BUGSLIFE_HOPPER_H
#define CA3_D00255161_BUGSLIFE_HOPPER_H

#include "bug.h"


class hopper : public bug {

public:
    using bug::bug;

    void move();
    void update();
};


#endif //CA3_D00255161_BUGSLIFE_HOPPER_H
