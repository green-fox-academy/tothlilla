//
// Created by Lilla on 2019. 01. 29..
//

#include "Sharpie.h"
#include <iostream>
#include <string>

Sharpie::Sharpie(std::string color, float width, int inkAmount)
{
    color_ = color;
    width_ = width;
    inkAmount_ = inkAmount;

}
void Sharpie::use()
{
    inkAmount_--;
}
int Sharpie::getInkAmount()
{
    return inkAmount_;
}
std::string Sharpie::sharpieState()
{
    std::string state = "The amount of the ink in the " + color_ + " sharpie, " + std::to_string(width_)
        + " wide sharpie is: " + std::to_string(getInkAmount()) + " %.";
    return state;

}