//
// Created by Lilla on 2019. 02. 06..
//
#include <iostream>
#include <string>
#include "copier.h"
Copier::Copier(int sizeX, int sizeY, int speed) : Printer2D(sizeX, sizeY), Scanner(speed)
{

}
void Copier::copy()
{
  scan();
  std::cout << " and ";
  print();
}