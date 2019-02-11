//
// Created by Lilla on 2019. 02. 05..
//

#ifndef EXBEFINHERITANCE_2_MENTOR_H
#define EXBEFINHERITANCE_2_MENTOR_H

#include "person.h"

enum Level
{
  JUNIOR,
  INTERMEDIATE,
  SENIOR
};

std::string getLevelString(Level level);

class Mentor: public Person
{
 public:
  Mentor();
  Mentor(std::string name, int age, Gender gender, Level level);
  void getGoal() override;
  void introduce() override;
 private:
  Level _level;

};

#endif //EXBEFINHERITANCE_2_MENTOR_H
