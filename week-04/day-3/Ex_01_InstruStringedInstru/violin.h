//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_01_INSTRUSTRINGEDINSTRU_VIOLIN_H
#define EX_01_INSTRUSTRINGEDINSTRU_VIOLIN_H
#include "stringedinstrument.h"
#include <iostream>
class Violin : public StringedInstrument
{
 public:
  Violin(int numberOfStrings);
  Violin(int numberOfStrings, int size);
  Violin();
  std::string sound() override;
  int _size;
};

#endif //EX_01_INSTRUSTRINGEDINSTRU_VIOLIN_H
