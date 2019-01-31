#include <iostream>

// Write a recursive function that takes one parameter: n and counts down from n.

void counter(int countNumber); //predefinition of counting function

int main() {
    std::cout << "Write a number :" << std::endl;
    int n; //1. the number of function calling, 2. the top number we want to count down
    std::cin >> n;
    counter(n);

    return 0;
}

void counter(int countNumber) //counting function
{
    if (countNumber >= 1) {
        std::cout << countNumber << std::endl;
        counter(countNumber - 1);
    }
}