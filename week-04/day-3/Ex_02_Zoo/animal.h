//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_02_ZOO_ANIMAL_H
#define EX_02_ZOO_ANIMAL_H
#include <iostream>
#include <string>
enum Gender
{
  MALE,
  FEMALE
};
std::string genderToString(Gender gender);
class Animal {
 public:
    virtual std::string getName() = 0;
    virtual std::string breed() = 0;
 protected:
  std::string _name;
  std::string color;
  int health;
  int _age;
  Gender _gender;

};

#endif //EX_02_ZOO_ANIMAL_H
