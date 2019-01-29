//
// Created by Lilla on 2019. 01. 29..
//

#include "Sharpie.h"
#include <iostream>
#include <string>

Sharpie::Sharpie(std::string colorS, float widthS)
{
    color = colorS;
    width = widthS;
}
void Sharpie::use() {
    inkAmount--;



}
