//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_02_ZOO_MAMMALS_H
#define EX_02_ZOO_MAMMALS_H
#include "animal.h"
class Mammal : public Animal {
 public:
  Mammal(std::string name);
  std::string getName() override;
  std::string breed() override;


};

#endif //EX_02_ZOO_MAMMALS_H
