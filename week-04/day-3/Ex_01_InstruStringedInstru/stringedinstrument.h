//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_01_INSTRUSTRINGEDINSTRU_STRINGEDINSTRUMENT_H
#define EX_01_INSTRUSTRINGEDINSTRU_STRINGEDINSTRUMENT_H
#include "instrument.h"

class StringedInstrument : public Instrument
{
 public:
  StringedInstrument(int numberOfStrings);
  StringedInstrument();
  virtual std::string sound() = 0;
  void play() override;
 protected:
  int _numberOfStrings;


};

#endif //EX_01_INSTRUSTRINGEDINSTRU_STRINGEDINSTRUMENT_H
