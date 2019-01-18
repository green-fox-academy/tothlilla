#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number form the standard input,
    int oneTwo;
    std::cout << "Write a number: " <<std::endl;
    std::cin >> oneTwo;
    // If the number is zero or smaller it should print: Not enough
    if (oneTwo == 0) {
        std::cout << "Not enough" << std::endl;
    } else if ( oneTwo == 1) {
        std::cout << "One" << std::endl;
    } else if ( oneTwo == 2) {
        std::cout << "Two" << std::endl;
    } else {
        std::cout << "A lot" << std::endl;
    }
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot

    return 0;
}