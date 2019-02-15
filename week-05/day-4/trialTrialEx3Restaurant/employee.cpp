//
// Created by Lilla on 2019. 02. 14..
//

#include "employee.h"
Employee::Employee(std::string name, int experience)
{
  _experience = experience;
  _name = name;
}
 std::string Employee::toString() {
  return (_name + " has " + std::to_string(_experience)) + " experience";
}
