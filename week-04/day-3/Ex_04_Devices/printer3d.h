//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_04_DEVICES_PRINTER3D_H
#define EX_04_DEVICES_PRINTER3D_H
#include "printer.h"


class Printer3D : public Printer {
 public:
  Printer3D(int sizeX, int sizeY, int sizeZ);
  std::string getSize() override;
 private:
  int _sizeX;
  int _sizeY;
  int _sizeZ;
};

#endif //EX_04_DEVICES_PRINTER3D_H
