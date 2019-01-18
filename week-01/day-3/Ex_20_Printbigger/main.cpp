#include <iostream>

#include <iostream>

int main(int argc, char* args[]) {
    int firstNum, secondNum;
    // Write a program that asks for two numbers and prints the bigger one
    std::cout << "Write the first number: " << std::endl;
    std::cin >> firstNum;
    std::cout << "Write the second number: " << std::endl;
    std::cin >> secondNum;
    if (firstNum > secondNum) {
        std::cout << firstNum << std::endl;
    } else {
        std::cout << secondNum << std::endl;
    }
    return 0;
}