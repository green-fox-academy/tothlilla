#include <iostream>
#include <fstream>
#include <string>
#include <exception>

int divide(int thenumber)
{
    int b;
    if (thenumber == 0) {
        throw std::string("fail");
    }
    b= 10/thenumber;
    return b;
}

int main() {
    int a;// Create a function that takes a number
    std::cout << "Write a number :" << std::endl; // divides ten with it,
    std::cin >> a;// and prints the result.
    try {
        std::cout << divide(a) << std::endl;;// It should print "fail" if the parameter is 0
    } catch (std::string e) {
        std::cout << e << std::endl;
    }


    return 0;
}
