//
// Created by Lilla on 2019. 02. 13..
//

#ifndef EX_10_PETROL_STATION_2_STATION_H
#define EX_10_PETROL_STATION_2_STATION_H
#include "car.h"

class Station {
 public:
  Station(int gasAmount);
  void fill(Car &onecar);


 private:
  int _gasAmount;
};

#endif //EX_10_PETROL_STATION_2_STATION_H
