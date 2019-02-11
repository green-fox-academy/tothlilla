#include <iostream>
#include "mother.h"
#include "daughter.h"
int main() {

  //Mother mom;
  //mom.sayName();

  Daughter tina;
  tina.sayName(); //it works without calling the base class
  tina.doSomething();

  return 0;
}