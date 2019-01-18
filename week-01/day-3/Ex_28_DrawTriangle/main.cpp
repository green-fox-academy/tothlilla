#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was

    int tringleRow;
    std::string starBase= "*";
    std::string star= "*";
    std::cout << "Write how many rows should the tringle have: " << std::endl;
    std::cin >> tringleRow;
    for (int i = 0; i < tringleRow; ++i) {
        std::cout << starBase << std::endl;
        starBase = starBase + star;

    }

    return 0;
}