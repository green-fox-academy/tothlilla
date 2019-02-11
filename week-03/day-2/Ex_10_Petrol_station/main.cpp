#include <iostream>
#include "car.h"
#include "station.h"

int main() {

    int carOneCapacity = 5;
    int carTwoCapacity = 36;
    int carThreeCapacity = 31;
    int carFourCapacity = 42;
    int carFiveCapacity  = 7;
    int carOneAmount = 0;
    int carTwoAmount = 2;
    int carThreeAmount = 0;
    int carFourAmount = 1;
    int carFiveAmount  = 3;

    Station stationCapacity(100);

    Car car1(carOneCapacity, carOneAmount);
    stationCapacity.fill(car1);
    Car car2(carTwoCapacity, carTwoAmount);
    stationCapacity.fill(car2);
    Car car3(carThreeCapacity, carThreeAmount);
    stationCapacity.fill(car3);
    Car car4(carFourCapacity, carFourAmount);
    stationCapacity.fill(car4);
    Car car5(carFiveCapacity, carFiveAmount);
    stationCapacity.fill(car5);
    //std::cout << remained.fill(car1) << std::endl;
    return 0;
}