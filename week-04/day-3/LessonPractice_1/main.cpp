#include <iostream>
#include "shape.h"
#include "rect.h"
#include "circle.h"
#include <vector>

/*ez csak a kiinduló minta, ezt átraktuk külön file-okba
 * class Shape{
  int x; //x koordináta pont 0
  int y; //y koordináta pont 0
 public:
  void move(int dx, int dy) //a mozgatási függvényem
  {
    x += dx;
    y += dy;
  }
  virtual double circumference () = 0; //azért használok double-t, mert törtet várok vissza kerület
  virtual double area() = 0; //terület
};
class Rect : public Shape {
  int width;
  int height;

  double circumference()
  {
    return 2 * width + 2 * height;
  }
  double area()
  {
    return width *  height;
  }
};*/
int main() {
  //Shape sh; //nem tudja meghívni, mert nem létező objectum, abstract

  std::vector<Shape*> shapes;//azért kell pointer, mert enélkül nem is tudom létrehozni (=0), iletve azért, mert így rámutat az alosztályokra és nem vágja le az egyéb tagokat
  Circle c(0, 0, 5);
  Rect r(0, 0 , 10, 10);
  shapes.push_back(&c);
  shapes.push_back(&r);
  shapes[0]->circumference();//futási időben rendeződik, hogy melyik circumstance-t használja, és felismeri, hogy az a köré, mert a 0. index a kör
  //(*shapes[0]).circumference(); ez a kettő ugyanaz, a -> kiváltja a deference-et
  shapes[1]->circumference();//ez a négyzet
  std::cout << shapes[0]->circumference() << std::endl; //2*5*3.14
  std::cout << shapes[1]->circumference() << std::endl; //2*10+2*10
  return 0;
}