//
// Created by Lilla on 2019. 02. 06..
//

#include "rect.h"
Rect::Rect(int x, int y, int w, int h) : Shape(x, y)
{
  width = w;
  height = h;
}
double Rect::circumference()
{
  return 2 * width + 2 * height;
}
double Rect::area()
{
  return width *  height;
}