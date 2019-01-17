#include <iostream>

int main(int argc, char* args[]) {

    // Swap the values of the variables
    int a = 123;
    int b = 526;
    int c = a;

    std::cout << a << std::endl;
    std::cout << b << std::endl;


    std::cout << (a = b) << std::endl;
    std::cout << (b = c) << std::endl;

    return 0;
}