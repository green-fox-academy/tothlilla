#include <iostream>

int main(int argc, char *args[]) {

    int a;
    std::cout << "Please give me a number: " << std::endl;
    std::cin >> a;
    std::string star = "*";
    std::string space = " ";


        for (int i = 0; i < a; i++) {

            for (int x = i; x < a; x++) {

                std::cout << space;
            }
            for (int j = 0; j <= i * 2; j++) {
                std::cout << star;

            }
            std::cout << std::endl;

        }





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

    return 0;
}