//
// Created by Lilla on 2019. 02. 06..
//
#include <iostream>
#include "printer.h"
void Printer::print()
{
  std::cout << "I'm printing something that's " << getSize() << " cm.";
}