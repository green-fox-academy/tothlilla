//
// Created by Lilla on 2019. 02. 03..
//
#include <iostream>
#include "student.h"
#include "gender.h"

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization)
{
  _name = name;
  _age = age;
  _gender = gender;
  _previousOrganization = previousOrganization;
  int _skippedDays;
}
Student::Student()
{

}
void Student::skipDays(int numberOfDays)
{
  _skippedDays += numberOfDays;
}
void Student::introduce()
{
  std::cout << "Hi, I'm " << _name << ", a " << _age << "year old " << _gender << "from " << _previousOrganization
  << "who skipped " << _skippedDays << "days from the course already." << std::endl;
}
void Student::getGoal()
{
  std::cout << "My goal is: Be a junior software developer." << std::endl;
}
