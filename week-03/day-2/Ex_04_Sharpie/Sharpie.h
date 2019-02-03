//
// Created by Lilla on 2019. 01. 29..
//
//Create Sharpie class
//  We should know about each sharpie their
//      color(which should be a string), width (which will be a floating point number), inkAmount (another floating point number)
//  When creating one, we need to specify the color and the width
//  Every sharpie is created with a default 100 as inkAmount
//  We can use() the sharpie objects
//      which decreases inkAmount

#ifndef EX_04_SHARPIE_SHARPIE_H
#define EX_04_SHARPIE_SHARPIE_H

#include <string>

class Sharpie
{
    public:
        Sharpie(std::string color, float width);
        int use();
    private:
        std::string _color;
        float _width;
        float _inkAmount = 100;
};


#endif //EX_04_SHARPIE_SHARPIE_H
