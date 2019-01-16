#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
    double a = 20;
    double b = 24.56;
    double c = 1.5;

    std::cout << "Surface Area: " << 2*(a*b+a*c+ b*c) << "\n" << "Volume: " << a*b*c << std::endl;

    return 0;
}