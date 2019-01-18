#include <iostream>

int main(int argc, char* args[]) {

    int numOne, numTwo;
    // Create a program that asks for two numbers
    std::cout << "Write two numbers: " << std::endl;
    std::cin >> numOne >> numTwo;
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    if (numTwo <= numOne) {
        std::cout << "The second number should be bigger" << std::endl;
    } else {
        for (int i = numOne; i < numTwo; ++i) {
            std::cout << i << std::endl;
        }
    }
    // If it is bigger it should count from the first number to the second by one
    //
    // example:
    //
    // first number: 3, second number: 6, should print:
    //
    // 3
    // 4
    // 5

    return 0;
}