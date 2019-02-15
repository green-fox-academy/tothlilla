//
// Created by Lilla on 2019. 02. 14..
//

#ifndef TRIALTRIALEX3RESTAURANT_RESTAURANT_H
#define TRIALTRIALEX3RESTAURANT_RESTAURANT_H

#include <string>
#include <vector>
#include "employee.h"
class Restaurant {

 public:
  Restaurant(std::string name, int foundYear);
  void guestsArrived();
  void hire(Employee &employee);
  std::string toStringRestaurant();

 private:
  std::string _name;
  int _foundationYear;
  std::vector<Employee*> _employees;



};

#endif //TRIALTRIALEX3RESTAURANT_RESTAURANT_H
