//
// Created by Lilla on 2019. 02. 06..
//
#include <iostream>
#include "printer2d.h"
Printer2D::Printer2D(int sizeX, int sizeY)
{
  _sizeX = sizeX;
  _sizeY = sizeY;
}

std::string Printer2D::getSize()
{
  return (std::to_string(_sizeX) + " X " + std::to_string(_sizeY));
}