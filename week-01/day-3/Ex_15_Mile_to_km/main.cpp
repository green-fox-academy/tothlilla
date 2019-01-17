#include <iostream>

int main(int argc, char* args[]) {
    int distanceKM;
    long double distKM;
    long double distanceML;
    std::cout << "Write the distance in whole kilometers: " <<std::endl;
    // Write a program that asks for an integer that is a distance in kilometers,
    std::cin >> distanceKM;
    distKM = distanceKM/1.;
    distanceML = distKM*1.609344;
    // then it converts that value to miles and prints it
    std::cout << distanceML <<std::endl;

    return 0;
}