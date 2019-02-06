//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_01_INSTRUSTRINGEDINSTRU_BASSGUITAR_H
#define EX_01_INSTRUSTRINGEDINSTRU_BASSGUITAR_H
#include "stringedinstrument.h"
class BassGuitar : public StringedInstrument {
 public:
  BassGuitar(int numberOfStrings);
  BassGuitar();
  std::string sound() override;
};

#endif //EX_01_INSTRUSTRINGEDINSTRU_BASSGUITAR_H
