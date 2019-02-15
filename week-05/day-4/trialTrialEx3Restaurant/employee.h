//
// Created by Lilla on 2019. 02. 14..
//

#ifndef TRIALTRIALEX3RESTAURANT_EMPLOYEE_H
#define TRIALTRIALEX3RESTAURANT_EMPLOYEE_H

#include <string>
class Employee {
 public:
  Employee(std::string name, int experience = 0); //a default van utoljára
  virtual void work() = 0;
  virtual std::string toString();

 private:
  std::string _name;

 protected:
  int _experience;

};

#endif //TRIALTRIALEX3RESTAURANT_EMPLOYEE_H
