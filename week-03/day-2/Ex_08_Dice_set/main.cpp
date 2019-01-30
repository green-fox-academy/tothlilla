#include <iostream>
#include "dice_set.h"
#include <vector>

int main(int argc, char* args[])
{
    // You have a `DiceSet` class which has a list for 6 dices
    // You can roll all of them with roll()
    // Check the current rolled numbers with getCurrent()
    // You can reroll with roll()
    // Your task is to roll the dices until all of the dices are 6

    DiceSet diceSet;


    diceSet.roll(); //We made just random number...

    for (int i = 0; i < 6; ++i) {
        std::cout << diceSet.getCurrent(i) << " "; //...and print them
    }

    std::cout << "\n" << std::endl;


    for (int k = 0; k < 6; ++k) {
        while (diceSet.getCurrent(k) != 6) { //We ask the getCurrent function to repeat the rolls until its value doesn't equal to 6
            diceSet.roll(k);
    }

    }
    for (int j = 0; j < 6; ++j) {
        std::cout << diceSet.getCurrent(j) << " "; //We print the value
    }


    return 0;
}
