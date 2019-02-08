//
// Created by Lilla on 2019. 02. 06..
//
#include <iostream>
#include "printer3d.h"
Printer3D::Printer3D(int sizeX, int sizeY, int sizeZ)
{
  _sizeX = sizeX;
  _sizeY = sizeY;
  _sizeZ = sizeZ;
}
std::string Printer3D::getSize()
{
  return (std::to_string(_sizeX) + " X " + std::to_string(_sizeY) + " X " + std::to_string(_sizeZ));
}