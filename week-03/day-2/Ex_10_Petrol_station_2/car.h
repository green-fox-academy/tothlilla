//
// Created by Lilla on 2019. 02. 13..
//

#ifndef EX_10_PETROL_STATION_2_CAR_H
#define EX_10_PETROL_STATION_2_CAR_H

class Car {
 public:
  Car(int gasAmount, int capacity);
  bool isFull();
  void fill();
 private:
  int _gasAmount;
  int _capacity;

};

#endif //EX_10_PETROL_STATION_2_CAR_H
