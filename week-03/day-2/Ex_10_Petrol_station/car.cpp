//
// Created by Lilla on 2019. 01. 30..
//

#include "car.h"
#include <iostream>

Car::Car(int capacity, int gasAmount)
{
    gasAmount_ = gasAmount;
    capacity_ = capacity;
}
bool Car::isFull()
{
      return capacity_ == gasAmount_;
}
void Car::fill()
{
    gasAmount_++;
}