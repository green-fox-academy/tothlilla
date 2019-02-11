//
// Created by Lilla on 2019. 02. 11..
//

#include "pirate.h"

Pirate::Pirate(std::string name, bool isCaptain, bool isWoodLeg)
{
  _healthPoint = 10;
  _name = name;
  _isCaptain = isCaptain;
  _isWoodLeg = isWoodLeg;

}

void Pirate::work()
{
 if (_isCaptain){
   _gold += 10;
   _healthPoint -=5;
 } else {
   _gold += 1;
   _healthPoint -=1;
 }
}
void Pirate::party()
{
  if (_isCaptain){
    _healthPoint +=5;
  } else {
    _healthPoint +=1;
  }
}
bool Pirate::captain() {

  return false;
}
bool Pirate::woodLeg() {

  return false;
}
std::string Pirate::toString() {
  if (_isWoodLeg){
    return ("Hello, I'm " + _name + ". I have a wooden leg and " + std::to_string(_gold) + " golds.");
  } else {
    return ("Hello, I'm " + _name + ". I still have my real legs and " + std::to_string(_gold) + " golds.");
  }
}

