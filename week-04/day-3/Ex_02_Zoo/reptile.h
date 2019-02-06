//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_02_ZOO_REPTILE_H
#define EX_02_ZOO_REPTILE_H
#include "byegg.h"
#include <iostream>
class Reptile : public Byegg {
 public:
  Reptile(std::string name);
  std::string getName()override;

};

#endif //EX_02_ZOO_REPTILE_H
