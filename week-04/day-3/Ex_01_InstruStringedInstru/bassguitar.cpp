//
// Created by Lilla on 2019. 02. 06..
//
#include <iostream>
#include "bassguitar.h"
BassGuitar::BassGuitar(int numberOfStrings) : StringedInstrument(numberOfStrings)
{
  _name = "Bass Guitar";
}
BassGuitar::BassGuitar() : StringedInstrument()
{
  _numberOfStrings = 4;
  _name = "Bass Guitar";
}
std::string BassGuitar::sound()
{
  return "Duum-duum-duum";
}