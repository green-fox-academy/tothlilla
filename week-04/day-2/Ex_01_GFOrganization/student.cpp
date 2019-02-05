//
// Created by Lilla on 2019. 02. 05..
//
#include <iostream>
#include "student.h"
Student::Student() :
  Person()
{
  _previousOrganization = "The School of Life";
  _skippedDays = 0;
}

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization) :
  Person(name, age, gender)
{
  _previousOrganization = previousOrganization;
  _skippedDays = 0;
}
void Student::skipDays(int numberOfDays)
{
  _skippedDays += numberOfDays;
}
void Student::getGoal()
{
  std::cout << "My goal is: Be a junior software developer." << std::endl;
}
void Student::introduce()
{
  std::cout <<  "Hi, I'm " << _name << ", a " << _age << " year old " << getGenderString(_gender) << " from "
  << _previousOrganization << " who skipped " << _skippedDays << " days from the course already." << std::endl;
}