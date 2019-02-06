//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_02_ZOO_BYEGG_H
#define EX_02_ZOO_BYEGG_H
#include "animal.h"

class Byegg : public Animal
{
 public:

  std::string breed() override;
};

#endif //EX_02_ZOO_BYEGG_H
