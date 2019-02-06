//
// Created by Lilla on 2019. 02. 06..
//

#include "electricguitar.h"
ElectricGuitar::ElectricGuitar(int numberOfStrings) : StringedInstrument(numberOfStrings){
  _name = "Electric Guitar";
}
ElectricGuitar::ElectricGuitar() : StringedInstrument()
{
  _numberOfStrings = 6;
  _name = "Electric Guitar";
}
std::string ElectricGuitar:: sound()
{
  return "Twang";
}