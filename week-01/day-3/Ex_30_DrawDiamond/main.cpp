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

    for (int k = 0; k < diamondLine/2; ++k) {
        for (int j = 0; j < startSpace; ++j) {
            std::cout << " ";

        }
        for (int j = 0; j < startStar; ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
        startSpace--;
        startStar = startStar+2;
    }


    return 0;

}