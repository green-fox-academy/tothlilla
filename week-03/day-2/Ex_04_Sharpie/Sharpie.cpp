//
// Created by Lilla on 2019. 01. 29..
//

#include "Sharpie.h"
#include <iostream>
#include <string>

Sharpie::Sharpie(std::string color, float width)
{
    _color = color;
    _width = width;
    _inkAmount;
}
int Sharpie::use() {
    _inkAmount--;
    return  _inkAmount;
}
