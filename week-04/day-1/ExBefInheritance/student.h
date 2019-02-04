//
// Created by Lilla on 2019. 02. 03..
//
#ifndef EXBEFINHERITANCE_STUDENT_H
#define EXBEFINHERITANCE_STUDENT_H
#include <string>
#include "gender.h"

class Student {
 public:
  Student(std::string name, int age, Gender gender, std::string previousOrganization);
  Student();
  void skipDays(int numberOfDays);
  void introduce();
  void getGoal();
  std::string _name = "Jane Doe";
  int _age = 30;
  Gender _gender = Gender::FEMALE;
  std::string _previousOrganization = "The School of Life";
  int _skippedDays = 0;
 private:

};

#endif //EXBEFINHERITANCE_STUDENT_H
