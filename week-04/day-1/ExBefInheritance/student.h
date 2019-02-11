//
// Created by Lilla on 2019. 02. 03..
//
#ifndef EXBEFINHERITANCE_STUDENT_H
#define EXBEFINHERITANCE_STUDENT_H
#include <string>
#include "person.h"
//#include "gender.h"

class Student {
 public:
  Student(std::string name, int age, Gender gender, std::string previousOrganization);
  Student();
  void skipDays(int numberOfDays);
  void introduce();
  void getGoal();

 private:
  std::string _name;
  int _age;
  Gender _gender;
  std::string _previousOrganization;
  int _skippedDays;
};

#endif //EXBEFINHERITANCE_STUDENT_H
