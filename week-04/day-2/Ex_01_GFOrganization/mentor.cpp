//
// Created by Lilla on 2019. 02. 05..
//

#include "mentor.h"
std::string getLevelString(Level level)
{
  if (level == Level::JUNIOR){
    return "junior";
  } else if (level == Level::INTERMEDIATE){
    return "intermediate";
  } else if (level == Level::SENIOR){
    return "senior";
  }
}
Mentor::Mentor() :
  Person()
{
  _level = Level::INTERMEDIATE;
}
Mentor::Mentor(std::string name, int age, Gender gender, Level level) :
  Person(name, age, gender)
{
  _level = level;
}
void Mentor::introduce()
{
  std::cout <<  "Hi, I'm " << _name << ", a " << _age << " year old " << getGenderString(_gender) << " " << getLevelString(_level) <<" mentor." << std::endl;
}
void Mentor::getGoal()
{
  std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}