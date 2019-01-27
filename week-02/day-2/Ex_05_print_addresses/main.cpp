#include <iostream>

int main()
{
    int a;
    int mynumbers[5];
    std::cout << "Write 5 numbers: " <<std::endl;
    for (int i = 0; i < 5; i++) { // Create a program which accepts five integers from the console (given by the user)
        std::cin >> a;            // and store them in an array
        mynumbers[i] = a;
    }

    int *mynumbersPtr = mynumbers;

    for (int i = 0; i < 5; i++) {
        std::cout << mynumbersPtr <<std::endl; // print out the memory addresses of the elements in the array
        ++mynumbersPtr;
    }

    return 0;
}


