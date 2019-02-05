//
// Created by Lilla on 2019. 02. 05..
//

#ifndef EX_01_GFORGANIZATION_SPONSOR_H
#define EX_01_GFORGANIZATION_SPONSOR_H

#include "person.h"
class Sponsor : public Person{
 public:
  Sponsor();
  Sponsor(std::string name, int age, Gender gender, std::string company);
  void introduce() override;
  void getGoal() override;
  void hire();

 protected:
 private:
  std::string _company;
  int _hiredStudents;

};

#endif //EX_01_GFORGANIZATION_SPONSOR_H
