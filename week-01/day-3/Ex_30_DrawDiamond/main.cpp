// Write a program that reads a number from the standard input, then draws a
// diamond like this:
//    *
//   ***
//  *****
// *******
//  *****
//   ***
//    *
//
// The diamond should have as many lines as the number was

#include <iostream>

int main(int argc, char* args[]) {
    int diamondLine;
    std::cout << "How big the diamond should be? ";
    std::cin >> diamondLine;
    int startSpace = diamondLine/2;
    int startStar = 1;

    for (int i = 0; i < diamondLine/2; ++i) {
        for (int j = 0; j < startSpace; ++j) {
          std::cout << " ";
        }
        for (int k = 0; k < startStar; ++k) {
          std::cout << "*";
        }
        std::cout << "\n";
        startSpace--;
        startStar = startStar + 2;
    }
  for (int l = 0; l < diamondLine / 2 +1 ; ++l) {
      for (int j = 0; j < startSpace; ++j) {
        std::cout << " ";
      }
      for (int m = 0; m < startStar; ++m) {
        std::cout << "*";
      }
      std::cout << "\n";
      startSpace++;
      startStar = startStar - 2;
  }
      return 0;
}