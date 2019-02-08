//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_04_DEVICES_PRINTER2D_H
#define EX_04_DEVICES_PRINTER2D_H
#include "printer.h"
class Printer2D : public Printer {
 public:
  Printer2D (int sizeX, int sizeY);
  std::string getSize() override;
 protected:
  int _sizeX;
  int _sizeY;


};

#endif //EX_04_DEVICES_PRINTER2D_H
