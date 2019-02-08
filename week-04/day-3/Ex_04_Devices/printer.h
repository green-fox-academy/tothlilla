//
// Created by Lilla on 2019. 02. 06..
//

#ifndef EX_04_DEVICES_PRINTER_H
#define EX_04_DEVICES_PRINTER_H
#include <iostream>

class Printer {
 public:
  virtual std::string getSize() = 0;
  void print();

};

#endif //EX_04_DEVICES_PRINTER_H
