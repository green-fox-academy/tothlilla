//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_02_ZOO_BIRD_H
#define EX_02_ZOO_BIRD_H

#include "byegg.h"

class Bird : public Byegg
{
 public:
  Bird(std::string name);
  std::string getName()override;

};

#endif //EX_02_ZOO_BIRD_H
