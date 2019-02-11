//
// Created by Lilla on 2019. 02. 06..
//

#ifndef LESSONPRACTICE_1_RECT_H
#define LESSONPRACTICE_1_RECT_H
#include "shape.h"

class Rect : public Shape {
  int width;
  int height;
 public:
  Rect(int x, int y, int w, int h);
  double circumference();
  double area();
};

#endif //LESSONPRACTICE_1_RECT_H
