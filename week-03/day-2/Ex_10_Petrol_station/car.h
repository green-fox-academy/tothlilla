//
// Created by Lilla on 2019. 01. 30..
//

#ifndef EX_10_PETROL_STATION_CAR_H
#define EX_10_PETROL_STATION_CAR_H


class Car {
public:
    Car(int capacity, int gasAmount);
    void fill();
    bool isFull();
    int gasAmount_;
    int capacity_;

private:

};


#endif //EX_10_PETROL_STATION_CAR_H
