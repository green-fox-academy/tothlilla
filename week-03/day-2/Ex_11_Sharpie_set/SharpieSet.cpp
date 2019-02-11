//
// Created by Lilla on 2019. 02. 01..
//
#include <iostream>
#include <vector>
#include "SharpieSet.h"
#include "Sharpie.h"

sharpieSet::sharpieSet(std::vector<Sharpie> something)
{
  sharpies = something;
}
int sharpieSet::countUsable()
{
  int tempSharpies = 0;

  for (int i = 0; i < sharpies.size(); i++) {

    if (sharpies[i].getInkAmount() > 0) {

    }
    tempSharpies++;
  }
  return tempSharpies;
}

void sharpieSet::removeTrash()
{
  for (int i = 0; i < sharpies.size(); i++) {
    if (sharpies[i].getInkAmount() == 0) {
      sharpies.erase(sharpies.begin() + i);
      i--;
    }
  }
}
