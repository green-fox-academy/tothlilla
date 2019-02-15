//
// Created by Lilla on 2019. 02. 14..
//

#include "restaurant.h"
void Restaurant::guestsArrived() {
  for (int i = 0; i < _employees.size(); ++i) {
    _employees[i]->work();
  }
}
void Restaurant::hire(Employee &employee) {
  _employees.push_back(&employee);
}
Restaurant::Restaurant(std::string name, int foundYear) {
_name= name;
_foundationYear = foundYear;
}
std::string Restaurant::toStringRestaurant() {
  std::string temp;
  for (int i = 0; i < _employees.size(); ++i) {
    temp += (_employees[i]->toString() +"\n");

  }
  return _name + " founded " + std::to_string(_foundationYear) + "\n" + temp;
}
