//
// Created by Lilla on 2019. 01. 30..
//
#include <iostream>
#include "station.h"

Station::Station(int gasAmount)
{
  gasAmount_ = gasAmount;
}

void Station::fill(Car car) {
    while (!car.isFull() && gasAmount_ > 0) {
      car.fill();
      gasAmount_--;
      std::cout << "Filling the car!" << std::endl;
    }
    std::cout << "Remaining gas amount of the station: " << gasAmount_ << std::endl;
    std::cout << "The gas amount in this car: " << car.gasAmount_ << std::endl;

}


/*    while(car.capacity_ != car.gasAmount_) {
        car.fill();
        gasAmount_--;
        std::cout << "Filling the car!" << std::endl;
      }
    std::cout << "Remaining gas amount of the station: " << gasAmount_ << std::endl;
}*/