//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_01_INSTRUSTRINGEDINSTRU_ELECTRICGUITAR_H
#define EX_01_INSTRUSTRINGEDINSTRU_ELECTRICGUITAR_H
#include "stringedinstrument.h"

class ElectricGuitar : public StringedInstrument
{
 public:
  ElectricGuitar(int numberOfStrings);
  ElectricGuitar();
  std::string sound() override;

};

#endif //EX_01_INSTRUSTRINGEDINSTRU_ELECTRICGUITAR_H
