//
// Created by josep on 23/04/2024.
//

#ifndef CA3_D00255161_BUGSLIFE_CRAWLER_H
#define CA3_D00255161_BUGSLIFE_CRAWLER_H

#include "bug.h"


class crawler : public  bug {

private:

public:
    crawler(char type, int id, int x, int y, int dir, int size);

    void move() override;
    //~crawler();
};


#endif //CA3_D00255161_BUGSLIFE_CRAWLER_H
