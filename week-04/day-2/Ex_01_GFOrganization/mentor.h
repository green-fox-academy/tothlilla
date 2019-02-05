//
// Created by Lilla on 2019. 02. 05..
//

#ifndef EX_01_GFORGANIZATION_MENTOR_H
#define EX_01_GFORGANIZATION_MENTOR_H

#include "person.h"
enum Level
{
  JUNIOR,
  INTERMEDIATE,
  SENIOR
};
std::string getLevelString(Level level);
class Mentor : public Person
{
 public:
  Mentor();
  Mentor(std::string name, int age, Gender gender, Level level);
  void introduce() override;
  void getGoal() override;
 protected:
 private:
  Level _level;


};

#endif //EX_01_GFORGANIZATION_MENTOR_H
