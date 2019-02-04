//
// Created by Lilla on 2019. 02. 03..
//
#ifndef EXBEFINHERITANCE_MENTOR_H
#define EXBEFINHERITANCE_MENTOR_H
#include <string>
#include "gender.h"

class Mentor {
 public:
  Mentor(std::string name, int age, Gender gender, std::string level);
  void introduce();
  void getGoal();
  std::string _name = "Jane Doe";
  int _age = 30;
  Gender _gender = Gender::FEMALE;
  std::string _level = "intermediate";
 private:
};

#endif //EXBEFINHERITANCE_MENTOR_H
