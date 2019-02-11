#include <iostream>
#include "mentor.h"
#include "person.h"
void demonstrateObjectslicing()
{
  Mentor m2("Maty", 27, Gender::MALE, Level::INTERMEDIATE);
  Person p = m2;
  p.getGoal();
  p.introduce();
}

void sayHello(Person p)
{
  p.introduce();
}
void sayHello2(Person &p)
{
  p.introduce();
}
int main()
{
  Person p("Pali", 23, Gender::MALE);
  p.getGoal();
  p.introduce();
  sayHello(p);

  std::cout << "\n";

  Person r;
  r.getGoal();
  r.introduce();

  std::cout << "\n";

  Mentor m;
  m.getGoal();
  m.introduce();

  std::cout << "\n";

  Mentor m2("Matyi", 26, Gender::MALE, Level::INTERMEDIATE);
  m2.getGoal();
  m2.introduce();

  std::cout << "\n";

  sayHello(m2); //elveszik így a mentor jellemző, ha nem referencia szerint adom át
  sayHello2(m2);//nem veszik el a mentor jellemző ha referencia szerint adom át!!
  demonstrateObjectslicing(); //example to slicing
  return 0;



}