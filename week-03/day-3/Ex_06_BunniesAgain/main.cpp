#include <iostream>

// We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
// (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
// have 3 ears, because they each have a raised foot. Recursively return the
// number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).

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
        if (bunnyNumber % 2 == 0){
                return oneBunnyEars + 1 +bunnyEars(bunnyNumber-1, oneBunnyEars);
            }else{
                return oneBunnyEars +bunnyEars(bunnyNumber-1, oneBunnyEars);
            }
        }
}