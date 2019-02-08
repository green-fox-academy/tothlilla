//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_04_DEVICES_COPIER_H
#define EX_04_DEVICES_COPIER_H

#include "scanner.h"
#include "printer2d.h"
class Copier : public Scanner, public Printer2D
{
 public:
  Copier(int sizeX, int sizeY, int speed);
  void copy();
};

#endif //EX_04_DEVICES_COPIER_H
