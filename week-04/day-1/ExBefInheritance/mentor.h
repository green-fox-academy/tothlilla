//
// Created by Lilla on 2019. 02. 03..
//
#ifndef EXBEFINHERITANCE_MENTOR_H
#define EXBEFINHERITANCE_MENTOR_H
#include <string>
#include "person.h"
//#include "gender.h"

class Mentor {
 public:
  Mentor(std::string name, int age, Gender gender, std::string level);
  Mentor();
  void introduce();
  void getGoal();
  std::string _name;
  int _age;
  Gender _gender;
  std::string _level;
 private:
};

#endif //EXBEFINHERITANCE_MENTOR_H
