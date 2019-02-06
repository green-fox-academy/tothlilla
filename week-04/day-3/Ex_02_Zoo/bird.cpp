//
// Created by Lilla on 2019. 02. 06..
//
#include <iostream>
#include "bird.h"
Bird::Bird(std::string name)
{
  _name = name;
  //breed();
}
std::string Bird::getName()
{
  return _name;
}