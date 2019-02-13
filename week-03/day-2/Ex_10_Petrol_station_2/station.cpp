//
// Created by Lilla on 2019. 02. 13..
//
#include <iostream>
#include "station.h"
Station::Station(int gasAmount)
{
_gasAmount = gasAmount;
}
void Station::fill(Car &onecar)
{
  while (!onecar.isFull() && _gasAmount > 0) {
    onecar.fill();
    std::cout << "Filling car!" << std::endl;
    _gasAmount--;
    if (onecar.isFull()){
      std::cout << "The remaining gas amount of the station :" << _gasAmount;
    }
  }
  if (_gasAmount == 0){
    std::cout << "No more petrol" << std::endl;
  }

}
