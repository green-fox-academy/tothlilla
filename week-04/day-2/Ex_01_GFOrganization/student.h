//
// Created by Lilla on 2019. 02. 05..
//

#ifndef EX_01_GFORGANIZATION_STUDENT_H
#define EX_01_GFORGANIZATION_STUDENT_H

#include "person.h"
class Student : public Person
{
 public:
  Student();
  Student(std::string name, int age, Gender gender, std::string previousOrganization);
  void getGoal() override;
  void introduce() override;
  void skipDays(int numberOfDays);
 private:
  int _skippedDays;
  std::string _previousOrganization;
};

#endif //EX_01_GFORGANIZATION_STUDENT_H
