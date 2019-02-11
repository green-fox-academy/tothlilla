//
// Created by Lilla on 2019. 02. 05..
//
#include <iostream>
#include "mother.h"
#include "daughter.h"

Daughter::Daughter()
{
  std::cout << "I'm the daughter constructor" << std::endl;
}
Daughter::~Daughter()
{
  std::cout << "I'm the daughter deconstructor" << std::endl;
}