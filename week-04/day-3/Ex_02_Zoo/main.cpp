#include <iostream>
#include "animal.h"
#include "mammals.h"

#include "bird.h"
#include "reptile.h"


int main( int argc, char* args[] )
{
  Reptile reptile("Crocodile");
  Mammal mammal("Koala");
  Bird bird("Parrot");

  std::cout << "How do you breed?" << std::endl;
  std::cout << "A " << reptile.getName() << " is breeding by " << reptile.breed() << std::endl;
  std::cout << "A " << mammal.getName() << " is breeding by " << mammal.breed() << std::endl;
  std::cout << "A " << bird.getName() << " is breeding by " << bird.breed() << std::endl;
}