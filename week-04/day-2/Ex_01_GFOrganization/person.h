//
// Created by Lilla on 2019. 02. 05..
//
#include <iostream>
#ifndef EX_01_GFORGANIZATION_PERSON_H
#define EX_01_GFORGANIZATION_PERSON_H
enum Gender
{
  MALE,
  FEMALE
};
std::string getGenderString(Gender gender);
class Person
{
 public:
  Person();
  Person(std::string name, int age, Gender gender);
  virtual void introduce();
  virtual void getGoal();
 protected:
  std::string _name;
  int _age;
  Gender _gender;
 private:

};

#endif //EX_01_GFORGANIZATION_PERSON_H
