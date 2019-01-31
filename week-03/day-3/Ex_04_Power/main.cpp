#include <iostream>

// Given base and n that are both 1 or more, compute recursively (no loops)
// the value of base to the n power, so powerN(3, 2) is 9 (3 squared).

int powerN(int baseNumber, int powerNumber);

int main() {

    int base, power;
    std::cout << "Write a number and the number to power the base number: ";
    std::cin >> base >> power;
    std::cout << powerN(base, power);
    return 0;
}

int powerN(int baseNumber, int powerNumber)
{
    if (powerNumber == 1){
        return baseNumber;
    } else {
        return (baseNumber * powerN(baseNumber, powerNumber-1));
    }
}