#include <iostream>

int main(int argc, char* args[]) {

    int squareLine;
    std::cout << "Write a number: ";
    std::cin >> squareLine;
    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%%
    // %    %
    // %    %
    // %    %
    // %    %
    // %%%%%%
    //
    // The square should have as many lines as the number was
    for (int i = 0; i < squareLine; ++i) {
        for (int j = 0; j < squareLine; ++j) {
            if (j == 0 || j == (squareLine-1) || i == 0 || i == (squareLine-1)) {
                std::cout << "%";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}