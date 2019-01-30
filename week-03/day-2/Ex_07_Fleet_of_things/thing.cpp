//
// Created by Lilla on 2019. 01. 30..
//

#include "thing.h"

Thing::Thing(const std::string& name)
{
    _name = name;
    _completed = false;
}

void Thing::complete()
{
    _completed = true;
}

std::string Thing::toString()
{
    return (_completed ? "[x] " : "[ ] ") + _name;
}