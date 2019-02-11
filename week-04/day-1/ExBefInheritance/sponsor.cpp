//
// Created by Lilla on 2019. 02. 03..
//
#include <iostream>
#include "sponsor.h"


Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company)
{
  _name = name;
  _age = age;
  _gender = gender;
  _company = company;
  _hiredStudents = 0;
}
Sponsor::Sponsor() {
  std::string _name = "Jane Doe";
  int _age = 30;
  Gender _gender = Gender::FEMALE;
  std::string _company = "Google";
  int _hiredStudents = 0;
}
void Sponsor::hire()
{
  _hiredStudents++;
}
void Sponsor::introduce()
{
  std::cout << "Hi, I'm " << _name << ", a " << _age << "year old " << getGenderString(_gender) << "who represents "<< _company << "and hired " <<
  _hiredStudents << "students so far." << std::endl;
}
void Sponsor::getGoal()
{
  std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}