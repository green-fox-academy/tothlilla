//
// Created by Lilla on 2019. 01. 30..
//

#ifndef EX_07_FLEET_OF_THINGS_FLEET_H
#define EX_07_FLEET_OF_THINGS_FLEET_H

#include <vector>
#include <string>

#include "thing.h"

class Fleet
{
public:
    Fleet();

    void add(const Thing& thing);
    std::string toString();

private:
    std::vector<Thing> things;
};


#endif //EX_07_FLEET_OF_THINGS_FLEET_H
