//
// Created by Lilla on 2019. 02. 03..
//
#ifndef EXBEFINHERITANCE_PERSON_H
#define EXBEFINHERITANCE_PERSON_H
#include <string>
#include "gender.h"

class Person
 {
 public:
    Person(std::string name, int age, Gender gender);
    Person();
    void introduce();
    void getGoal();
    std::string _name = "Jane Doe";
    int _age = 30;
    Gender _gender = Gender::FEMALE;
 private:
 };

/* public:
  Person(std::string name, int age, std::string gender);
  Person();
  void introduce();
  void getGoal();
  std::string _name = "Jane Doe";
  int _age = 30;
  std::string _gender = "female";
 private:
  std::string enum_to_string(Gender gender)
  {
    switch (gender) {
      case Gender::MALE:
        return std::string("male");
      case Gender::FEMALE:
        return std::string("female");
    }
  }
};
*/
#endif //EXBEFINHERITANCE_PERSON_H
