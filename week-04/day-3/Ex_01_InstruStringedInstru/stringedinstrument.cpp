//
// Created by Lilla on 2019. 02. 06..
//

#include "stringedinstrument.h"
#include <iostream>

StringedInstrument::StringedInstrument(int numberOfStrings)
{
  _numberOfStrings = numberOfStrings;
}
StringedInstrument::StringedInstrument()
{
  _numberOfStrings = 0;
}

void StringedInstrument::play()
{
  std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;
}