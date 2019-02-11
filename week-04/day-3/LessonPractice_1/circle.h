//
// Created by Lilla on 2019. 02. 06..
//

#ifndef LESSONPRACTICE_1_CIRCLE_H
#define LESSONPRACTICE_1_CIRCLE_H
#include "shape.h"

class Circle : public Shape {
  int radius;
 public:
  Circle(int x, int y, int rad);
  double circumference();
  double area();

};

#endif //LESSONPRACTICE_1_CIRCLE_H
