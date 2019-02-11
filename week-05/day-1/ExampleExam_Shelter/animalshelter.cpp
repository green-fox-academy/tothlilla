//
// Created by Lilla on 2019. 02. 11..
//

#include "animalshelter.h"
#include <iostream>
#include <sstream>
std::string AnimalShelter::toString() {

  std::stringstream result;
  result << "Budget: " << _budget << " eur";
  result << ", There are " << _animals.size();
  result << " animal(s) and";
  result << _adopters.size() << " potential adopter(s)";
  result << std::endl;
  for (int i = 0; i < _animals.size(); ++i) {
    result << _animals[i].toString() << std::endl;
  }

  return result.str();
}
int AnimalShelter::rescue(Animal animal)
{
  _animals.push_back(animal);

  return _animals.size();
}
bool AnimalShelter::heal() {


  return ;
}
