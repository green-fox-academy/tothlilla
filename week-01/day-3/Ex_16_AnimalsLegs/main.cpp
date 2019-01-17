#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    int numbChick;
    // The second represents the number of pigs owned by the farmer
    int numbPig;
    // It should print how many legs all the animals have
    std::cout << "Write the numbers of chickens and pigs: " <<std::endl;
    std::cin >> numbChick >> numbPig;
    std::cout << "All the chickens and the pigs on the farm is " << numbChick*2+numbPig*4 <<std::endl;

    return 0;
}