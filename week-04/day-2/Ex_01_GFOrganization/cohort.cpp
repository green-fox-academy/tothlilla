//
// Created by Lilla on 2019. 02. 05..
//

#include "cohort.h"

Cohort::Cohort(std::string name)
{
  _name = name;
}
void Cohort::addStudent(Student* s) //Studentre mutató pointer
{
  _students.push_back(*s);
}

void Cohort::addMentor(Mentor *m) //Studentre mutató pointer
{
  _mentors.push_back(*m);
}
void Cohort::info()
{
  std::cout << "The " << _name << " cohort has " << _students.size() << " students and " << _mentors.size() << " mentors." << std::endl;
}



