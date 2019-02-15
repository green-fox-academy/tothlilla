#include <iostream>
#include "employee.h"
#include "restaurant.h"
#include "waitor.h"
#include "chef.h"
#include "manager.h"
int main() {
  std::cout << "Hello, World!" << std::endl;



  Waitor waiter ("balazs", 5);
  Chef c ("Top", 6);
  Chef c2 ("Vice",4);
  Manager m("Fread", 7);

  Restaurant r("Riso", 50);
  r.hire(c);
  r.hire(waiter);
  r.hire(m);
  r.hire(c2);

  c.cook("Soup");
  c.cook("Pasta");
  c.cook("Pizza");
  c2.cook("Soup");

  r.guestsArrived();
  
  m.haveAmeeting();
  m.haveAmeeting();
  m.haveAmeeting();



  std::cout << c.toString();

  std::cout << r.toStringRestaurant();



  return 0;
}