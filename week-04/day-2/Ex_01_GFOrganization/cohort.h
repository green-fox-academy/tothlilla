//
// Created by Lilla on 2019. 02. 05..
//

#ifndef EX_01_GFORGANIZATION_COHORT_H
#define EX_01_GFORGANIZATION_COHORT_H
#include <iostream>
#include <vector>
#include "student.h"
#include "mentor.h"
class Cohort {
 public:
  Cohort(std::string name);
  void addStudent(Student*);
  void addMentor(Mentor*);
  void info();
 protected:
 private:

  std::string _name;
  std::vector<Student> _students; //a vector elkészül
  std::vector<Mentor> _mentors;
};

#endif //EX_01_GFORGANIZATION_COHORT_H
