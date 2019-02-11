#include <iostream>
int main() {
  for (int i = 2; i < 100; i++){
      for (int j = 2; j <= (i / j); ++j) {
          if (!(i % j)) {
              break;
          }
          if (j > (i / j)) {
              std::cout << i << " is prime" << std::endl;
          }
      }
  }

  return 0;
}