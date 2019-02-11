//
// Created by Lilla on 2019. 02. 05..
//

#include <iostream>
#include "mother.h"
#include "daughter.h"
Mother::Mother()
{
    std::cout << "I'm the mother constructor" << std::endl;
}
Mother::~Mother()
{
  std::cout << "I'm the mother deconstructor" << std::endl;
}
