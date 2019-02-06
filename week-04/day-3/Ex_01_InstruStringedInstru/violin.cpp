//
// Created by Lilla on 2019. 02. 06..
//
#include <iostream>
#include "violin.h"
Violin::Violin(int numberOfStrings) : StringedInstrument(numberOfStrings)
{
 _name = "Violin";
}
/* PLAY
 * Violin::Violin(int numberOfStrings, int size) : StringedInstrument (numberOfStrings)
{
  _name = "Violin";
  _size = size;
}*/
Violin::Violin() : StringedInstrument()
{
  _numberOfStrings = 4;
  _name = "Violin";
}
std::string Violin::sound()
{
  return "Screech";
}