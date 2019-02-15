//
// Created by Lilla on 2019. 02. 14..
//

#ifndef TRIALTRIALEX3RESTAURANT_WAITOR_H
#define TRIALTRIALEX3RESTAURANT_WAITOR_H
#include "employee.h"
class Waitor : public Employee{
 public:
  Waitor(std::string name, int experience = 0);
  void work() override;
 private:
  int _tips = 0;

};

#endif //TRIALTRIALEX3RESTAURANT_WAITOR_H
