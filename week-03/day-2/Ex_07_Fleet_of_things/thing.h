//
// Created by Lilla on 2019. 01. 30..
//

#ifndef EX_07_FLEET_OF_THINGS_THING_H
#define EX_07_FLEET_OF_THINGS_THING_H

#include <string>

class Thing
{
public:
    Thing(const std::string& name);

    void complete();
    std::string toString();

private:
    std::string _name;
    bool _completed;
};





#endif //EX_07_FLEET_OF_THINGS_THING_H
