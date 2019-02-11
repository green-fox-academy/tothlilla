//
// Created by Lilla on 2019. 02. 03..
//
#include <iostream>
#include "student.h"
//#include "gender.h"

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization)
{
  _name = name;
  _age = age;
  _gender = gender;
  _previousOrganization = previousOrganization;
  int _skippedDays =0;
}
Student::Student()
{
  std::string _name = "Jane Doe";
  int _age = 30;
  Gender _gender = Gender::FEMALE;
  std::string _previousOrganization = "The School of Life";
  int _skippedDays =0;
}
void Student::skipDays(int numberOfDays)
{
  _skippedDays += numberOfDays;
}
void Student::introduce()
{
  std::cout << "Hi, I'm " << _name << ", a " << _age << "year old " << getGenderString(_gender) << "from " << _previousOrganization
  << "who skipped " << _skippedDays << "days from the course already." << std::endl;
}
void Student::getGoal()
{
  std::cout << "My goal is: Be a junior software developer." << std::endl;
}
