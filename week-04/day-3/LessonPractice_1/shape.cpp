//
// Created by Lilla on 2019. 02. 06..
//

#include "shape.h"
Shape::Shape (int x, int y)
{
  _x = x; //this -> x = x; abban az esetben, ha kint csak x volt
  _y = y; //this -> y = y; abban az esetben, ha kint csak x volt
}
void Shape::set_x(int x)
{
  _x = x;
  //this -> x = x;
  //(this -> x)++; pl.: így használom az incrementálást
}
void Shape::move(int dx, int dy) //a mozgatási függvényem
{
  _x += dx;
  _y += dy;
}
