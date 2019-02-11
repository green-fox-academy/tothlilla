//
// Created by Lilla on 2019. 02. 06..
//

#include "circle.h"
Circle::Circle(int x, int y, int rad) : Shape(x, y)
{
  radius = rad;
}
double Circle::circumference()
{
  return 2 * radius * 3.14;
}
double Circle::area()
{
  return radius * radius * 3.14;
}