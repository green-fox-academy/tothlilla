#include <iostream>
#include "person.h"
#include "student.h"
#include "farmer.h"

void whosThisPerson(Person &p);

int main() {
  Farmer anil;
  Student alex;

  whosThisPerson(anil); //ha virtual nélkül használom, akkor a Person szövegét írja ki, ha virtuallal, akkor a farmerét
  whosThisPerson(alex); //ha virtuallal használom, de a Farmerből törlöm a beírandó szöveget, akkor a base class értékét adja vissza
  return 0;
}

void whosThisPerson(Person &p)
{
  p.introduce();
}