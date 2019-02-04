//
// Created by Lilla on 2019. 02. 03..
//
#ifndef EXBEFINHERITANCE_SPONSOR_H
#define EXBEFINHERITANCE_SPONSOR_H
#include <string>
#include "gender.h"

class Sponsor {
 public:
  Sponsor(std::string name, int age, Gender gender, std::string company);
  void hire();
  void introduce();
  void getGoal();
  std::string _name = "Jane Doe";
  int _age = 30;
  Gender _gender = Gender::FEMALE;
  std::string _company = "Google";
  int _hiredStudents = 0;

 private:
};

#endif //EXBEFINHERITANCE_SPONSOR_H
