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

#ifndef EX_05_COUNTER_COUNTER_H
#define EX_05_COUNTER_COUNTER_H


class Counter {
public:
    Counter(int number = 0); //Here give the default value, if it is necessary

    void add(int x);

    void add();

    int get(); //It has a return value

    void reset();


private:
    int number_;
    int number_start_; //It will take up the starting number (default or specified). We need this because of reset() function

};


#endif //EX_05_COUNTER_COUNTER_H
