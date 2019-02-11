//
// Created by Lilla on 2019. 02. 11..
//

#include "animal.h"
#include <iostream>
Animal::Animal()
{

}
Animal::Animal(std::string name, int healthCost)
{
  _name = name;
  _healthCost = healthCost;
}
std::string Animal::toString() {
  if (_isHealty) {
  return _name + " is healty and adoptable";
} else {
    return _name + " is not healty (" + std::to_string(_healthCost) + "eur) and not adoptaple";
  }
}
