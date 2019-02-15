//
// Created by Lilla on 2019. 02. 14..
//

#ifndef TRIALTRIALEX3RESTAURANT_CHEF_H
#define TRIALTRIALEX3RESTAURANT_CHEF_H
#include "employee.h"
#include <map>

class Chef : public Employee{
 public:
  Chef(std::string name, int experience = 0);
  void work() override;
  void cook(std::string foodName);


 private:
  std::map<std::string, int> _meals;


};

#endif //TRIALTRIALEX3RESTAURANT_CHEF_H
