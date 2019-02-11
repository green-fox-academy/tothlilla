//
// Created by Lilla on 2019. 02. 03..
//
#ifndef EXBEFINHERITANCE_2_PERSON_H
#define EXBEFINHERITANCE_2_PERSON_H
#include <string>

enum Gender
{
  MALE,
  FEMALE
};
std::string getGenderString(Gender gender);
class Person
{
 public:
  Person(std::string name, int age, Gender gender);
  Person();
  virtual void introduce(); //ezzel engedélyezem a leszármazottaknak, hogy másként is viselkedjenek
  virtual void getGoal();
 protected: //ezt kell használnom a private helyett, hogy a leszármazottak is lássák, viszont a main nem látja!!!
  std::string _name;
  int _age;
  Gender _gender;
};

#endif //EXBEFINHERITANCE_2_PERSON_H
