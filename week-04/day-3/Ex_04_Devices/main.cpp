#include <iostream>
#include <vector>
#include "printer.h"
#include "printer2d.h"
#include "printer3d.h"
#include "copier.h"
#include "scanner.h"
int main() {

  Printer2D Hp(30, 40);
  Printer2D Cannon(40, 40);
  Printer2D LG(20, 60);
  Printer3D Creality(20, 10, 50);
  Printer3D idontknow(20, 60, 50);
  Copier Sharp(20, 30, 500);
  Copier Sharp2(20, 40, 150);
  Scanner Epson(200);
  Scanner Fujitsu(300);

  std::vector<Printer*> allPrinters;
  allPrinters.push_back(&Hp);
  allPrinters.push_back(&Cannon);
  allPrinters.push_back(&LG);
  allPrinters.push_back(&Creality);
  allPrinters.push_back(&idontknow);
  allPrinters.push_back(&Sharp);

  std::vector<Scanner*> myScanners;
  myScanners.push_back(&Epson);
  myScanners.push_back(&Fujitsu);
  myScanners.push_back(&Sharp);
  myScanners.push_back(&Sharp2);

  for (int i = 0; i < allPrinters.size(); ++i) {
    allPrinters[i]->print();
    std::cout << "\n";
  }
  for (int i = 0; i < myScanners.size(); ++i) {
    myScanners[i]->scan();
    std::cout << "\n";
  }
  Sharp.copy();

  return 0;
}

  //for (std::vector<Printer*>::iterator it = allPrinters.begin(); it != allPrinters.end(); it++) {
  //  std::cout <<  << std::endl;
  //}