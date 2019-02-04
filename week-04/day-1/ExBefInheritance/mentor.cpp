//
// Created by Lilla on 2019. 02. 03..
//
#include <iostream>
#include "mentor.h"
#include "gender.h"

Mentor::Mentor(std::string name, int age, Gender gender, std::string level)
{
  _name = name;
  _age = age;
  _gender = gender;
  _level = level;
}
void Mentor::introduce()
{
  std::cout << "Hi, I'm " << _name << ", a " << _age << "year old " << _gender << _level << "mentor." << std::endl;
}
void Mentor::getGoal()
{
  std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}