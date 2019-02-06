//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_01_INSTRUSTRINGEDINSTRU_INSTRUMENT_H
#define EX_01_INSTRUSTRINGEDINSTRU_INSTRUMENT_H

#include <string>
#include <iostream>
class Instrument {
 public:
  virtual void play() = 0;
 protected:
  std::string _name;


};

#endif //EX_01_INSTRUSTRINGEDINSTRU_INSTRUMENT_H
