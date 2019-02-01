//
// Created by Lilla on 2019. 01. 30..
//

#ifndef EX_10_PETROL_STATION_STATION_H
#define EX_10_PETROL_STATION_STATION_H

#include "car.h"
class Station {

public:
    Station (int gasAmount);
    void fill(Car car);

private:
    int gasAmount_;
};


#endif //EX_10_PETROL_STATION_STATION_H
