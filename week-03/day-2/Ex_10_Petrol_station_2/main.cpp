#include <iostream>
#include "car.h"
#include "station.h"

int main() {


  Station oneStationCapacity(100);

  Car car1(2, 200);
  Car car2(5, 50);
  Car car3(0, 10);
  Car car4(2,5);

  oneStationCapacity.fill(car1);
  oneStationCapacity.fill(car2);
  oneStationCapacity.fill(car3);
  oneStationCapacity.fill(car4);
  return 0;
}