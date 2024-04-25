//
// Created by josep on 23/04/2024.
//

#ifndef CA3_D00255161_BUGSLIFE_CRAWLER_H
#define CA3_D00255161_BUGSLIFE_CRAWLER_H

#include "bug.h"


class crawler : public  bug {

public:
    using bug::bug;

    void move();
    void update();

};


#endif //CA3_D00255161_BUGSLIFE_CRAWLER_H
