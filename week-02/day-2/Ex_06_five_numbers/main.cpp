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
        std::cout << *mynumbersPtr <<std::endl; // print out the values of that array using pointers again
        ++mynumbersPtr; //léptetni kell a deference-t is, mert enélkül csak az első elemet nyomtatjuk ki 5-ször
    }
    //Second solution
    //for (int i = 0; i < 5; i++) {
    //    std::cout << *(mynumbersPtr + i) <<std::endl; // print out the values of that array using pointers again
    //}
    return 0;
}