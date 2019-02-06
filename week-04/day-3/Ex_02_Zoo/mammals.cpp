//
// Created by Lilla on 2019. 02. 06..
//

#include "mammals.h"
#include <iostream>
Mammal::Mammal(std::string name)
{
  _name = name;
}
std::string Mammal::getName()
{
  return _name;
}
std::string Mammal::breed()
{
  return "pushing miniature versions out";
}
