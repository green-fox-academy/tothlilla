#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was

    int pyramidRow;

    std::string starBase = "*";
    std::string star = "**";
    std::string spaceBase = " ";
    std::cout << "Write how many rows should the tringle have: " << std::endl;
    std::cin >> pyramidRow;
    int forSpace = pyramidRow;
    for (int i = 0; i < pyramidRow; ++i) {

        for (int j = (forSpace - 1); j > 0; --j) {
            std::cout << spaceBase;
        }

        std::cout << starBase;
        starBase = starBase + star;

        for (int j = (forSpace - 1); j > 0; --j) {
            std::cout << spaceBase;
        }
        forSpace = forSpace - 1;
        std::cout << std::endl;
    }



    return 0;
}