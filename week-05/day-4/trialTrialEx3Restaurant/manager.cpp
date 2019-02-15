//
// Created by Lilla on 2019. 02. 14..
//

#include "manager.h"
void Manager::work() {
  _experience++;

}
void Manager::haveAmeeting() {
  _moodLevel-=_experience;
}
Manager::Manager(std::string name, int experience) :
  Employee(name, experience) {

}
std::string Manager::toString() {


  return Employee::toString() + " and he have a " + std::to_string(_moodLevel) + " mood";
}
