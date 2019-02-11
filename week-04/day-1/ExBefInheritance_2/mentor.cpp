//
// Created by Lilla on 2019. 02. 05..
//
#include <iostream>
#include "mentor.h"

std::string getLevelString(Level level)
{
  if(level == Level::INTERMEDIATE){
    return "intermediate";
  } else if (level == Level::JUNIOR) {
    return "junior";
  } else if (level == Level::SENIOR) {
    return "senior";
  }
}
Mentor::Mentor()
//Mentor::Mentor() :
//  Person()
{
  _level = Level::INTERMEDIATE;
};
Mentor::Mentor(std::string name, int age, Gender gender, Level level) :
  Person(name, age, gender)//ha az ősosztályból valamelyik adatot meg akaorm változtatni, akkor itt tudom. Pl.: az age helyett azt írom, hogy 20!!!!!!
{
 _level = level;
}
void Mentor::getGoal()
{
  std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}
void Mentor::introduce()
{
  std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << getGenderString(_gender)
  << " " << getLevelString(_level) << " mentor" << std::endl;
}