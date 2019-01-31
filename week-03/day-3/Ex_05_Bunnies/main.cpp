#include <iostream>

// We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).

int bunnyEars(int bunnyNumber, int oneBunnyEars);

int main() {

    int bunnyNumb;
    int BunnyEars = 2;
    std::cout << "Write the numbers of bunnies: ";
    std::cin >> bunnyNumb;
    std::cout << bunnyEars(bunnyNumb, BunnyEars);
    return 0;
}

int bunnyEars(int bunnyNumber, int oneBunnyEars)
{
    if (bunnyNumber <= 1){
        return oneBunnyEars;
    } else {
        return (oneBunnyEars + bunnyEars(bunnyNumber-1, oneBunnyEars));
    }
}