//
// Created by Lilla on 2019. 02. 01..
//

#ifndef EX_11_SHARPIE_SET_SHARPIESET_H
#define EX_11_SHARPIE_SET_SHARPIESET_H
#include <vector>
#include <iostream>
#include "Sharpie.h"
class sharpieSet
{
   public:
      sharpieSet(std::vector<Sharpie> something);
      int countUsable();
      void removeTrash();

   private:
      std::vector<Sharpie> sharpies;
};

#endif //EX_11_SHARPIE_SET_SHARPIESET_H
