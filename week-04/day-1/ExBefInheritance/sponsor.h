//
// Created by Lilla on 2019. 02. 03..
//
#ifndef EXBEFINHERITANCE_SPONSOR_H
#define EXBEFINHERITANCE_SPONSOR_H
#include <string>
//#include "gender.h"
#include "person.h"

class Sponsor {
 public:
  Sponsor(std::string name, int age, Gender gender, std::string company);
  Sponsor();
  void hire();
  void introduce();
  void getGoal();
  std::string _name = "Jane Doe";
  int _age ;
  Gender _gender;
  std::string _company;
  int _hiredStudents;

 private:
};

#endif //EXBEFINHERITANCE_SPONSOR_H
