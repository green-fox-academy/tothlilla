//
// Created by Lilla on 2019. 01. 29..
//
//Create Counter class
//  which has an integer field value
//  when creating it should have a default value 0 or we can specify it when creating
//  we can add(number) to this counter another whole number
//  or we can add() without parameters just increasing the counter's value by one
//  and we can get() the current value
//  also we can reset() the value to the initial value
//Check if everything is working fine with the proper test
//  Download main.cpp and use that instead of the default
//  Without modifying anything in it, compile and run.
//  Check the console output whether any of the tests failed.

#include "Counter.h"
#include <iostream>

Counter::Counter(int number) { //Constructor is used for giving back "values" of itself without any operations
    number_ = number;
    number_start_ = number;
}
void Counter::add(int x) {
    number_ = number_ + x;
}
void Counter::add() {
    number_++;
}
int Counter::get() {
    return number_;
}
void Counter::reset(){
    number_ = number_start_;
}