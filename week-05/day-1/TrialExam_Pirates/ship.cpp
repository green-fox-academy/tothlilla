//
// Created by Lilla on 2019. 02. 11..
//

#include "ship.h"
#include <algorithm>
Ship::Ship()
{

}

void Ship::addPirate(Pirate onepirate) {
  //_pirates.push_back(onepirate);
  if (!onepirate.captain()){
    _pirates.push_back(onepirate);
  }

  if (onepirate.captain()){
    for (int i = 0; i < _pirates.size(); ++i) {
      if (_pirates[i].captain()){
        return;
      } else {
        _pirates.push_back(onepirate);
      }
    }
  }
}
std::vector<std::string> Ship::getPoorPirates()
{
  std::vector<std::string> _poorPirates;
  for (int i = 0; i < _pirates.size(); ++i) {
    if (_pirates[i].woodLeg() || _pirates[i].getGold() < 15){
      _poorPirates.push_back(_pirates[i].getName());
    }
  }
  return _poorPirates;
}
int Ship::getGolds()
{
  int sum = 0;
  for (int i = 0; i < _pirates.size(); ++i) {
    sum += _pirates[i].getGold();
  }
  return sum;
}
void Ship::lastDayOnTheShip()
{
  for (int i = 0; i < _pirates.size(); ++i) {
    _pirates[i].party();
  }
}
void Ship::prepareForBattle()
{
  for (int i = 0; i < _pirates.size(); ++i) {
    for (int j = 0; j < 5; ++j) {
      _pirates[i].work();
    }
  }
  lastDayOnTheShip();
}

