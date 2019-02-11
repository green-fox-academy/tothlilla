//
// Created by Lilla on 2019. 02. 06..
//

#ifndef LESSONPRACTICE_1_SHAPE_H
#define LESSONPRACTICE_1_SHAPE_H

class Shape{
 protected:
  int _x; //x koordináta pont 0
  int _y; //y koordináta pont 0

  //int x; ezt a két változót csak a this -> x = x miatt használjuk
  //int y;
 public:
  Shape (int x, int y); // nem tudok vele dolgozni itt, csak származtatni

  void set_x(int x);
  void move(int dx, int dy); //a mozgatási függvényem
  virtual double circumference () = 0; //azért használok double-t, mert törtet várok vissza kerület
  virtual double area() = 0; //terület
};

#endif //LESSONPRACTICE_1_SHAPE_H
