//
// Created by Lilla on 2019. 02. 11..
//

#ifndef EXAMPLEEXAM_SHELTER_ANIMAL_H
#define EXAMPLEEXAM_SHELTER_ANIMAL_H
#include <iostream>

class Animal
{
 public:
  Animal();
  Animal(std::string name, int healthCost);
  std::string toString();

 private:
  std::string _name;
  bool _isHealty = false;
  int _healthCost;
};

#endif //EXAMPLEEXAM_SHELTER_ANIMAL_H
