//
// Created by Lilla on 2019. 02. 14..
//

#ifndef TRIALTRIALEX3RESTAURANT_MANAGER_H
#define TRIALTRIALEX3RESTAURANT_MANAGER_H
#include "employee.h"
class Manager :public Employee{
 public:

Manager(std::string name, int experience = 0);
  void work() override;
  void haveAmeeting();
  std::string toString() override;
 private:
  int _moodLevel =400;

};

#endif //TRIALTRIALEX3RESTAURANT_MANAGER_H
