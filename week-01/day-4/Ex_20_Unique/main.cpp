#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example

    int i;
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    int size = sizeof(numbers)/ sizeof(numbers[0]);
    int unique[size][size];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            unique[i] [j]= n#include <iostream>

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
}umbers[i];
        }
    }

    std::cout << "Give size of the list: " << std::endl;
    std::cin >> numbers [i];


    int middle = numbers [i];
    if (numbers [i] {
        std::cout << (unique(numbers)) << std::endl;
    }
    //  should print: `[1, 11, 34, 52, 61]`

    return 0;
}