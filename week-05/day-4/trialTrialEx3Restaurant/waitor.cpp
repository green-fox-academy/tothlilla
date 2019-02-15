//
// Created by Lilla on 2019. 02. 14..
//

#include "waitor.h"
void Waitor::work() {
  _tips++;
  _experience++;

}
Waitor::Waitor(std::string name, int experience) :
    Employee(name, experience)
{

}
std::string Waitor::toString() {
  return (Employee::toString() + " and got " + std::to_string(_tips) + " dollar for tips");
}
