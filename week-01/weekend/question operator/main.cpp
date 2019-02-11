#include <iostream>
int main() {
  int x, y = 10;
  x = (y < 10) ? 30 : 40;
  std::cout << "values of x " << x << std::endl;
  return 0;
}