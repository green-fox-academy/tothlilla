//
// Created by Lilla on 2019. 02. 13..
//

#include "car.h"
Car::Car(int gasAmount, int capacity)
{
  _gasAmount = gasAmount;
  _capacity = capacity;
}
bool Car::isFull() {
  if (_gasAmount != _capacity){
    return false;
  }
  return true;
}
void Car::fill()
{
  _gasAmount++;
}
