//
// Created by Lilla on 2019. 02. 11..
//

#ifndef EXAMPLEEXAM_SHELTER_ANIMALSHELTER_H
#define EXAMPLEEXAM_SHELTER_ANIMALSHELTER_H
#include "animal.h"
#include <vector>

class AnimalShelter
{
 public:
  int rescue(Animal animal);
  std::string toString();
  bool heal();

 private:

  int _budget = 50;
  std::vector<Animal> _animals;
  std::vector<std::string> _adopters;

};

#endif //EXAMPLEEXAM_SHELTER_ANIMALSHELTER_H
