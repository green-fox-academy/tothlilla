#include <iostream>

// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.

int adder(int addNumber);       //predefinition of adding function

int main() {
    std::cout << "Write a number :" << std::endl;
    int n;                      //1. the number of function calling, 2. the top number we want to add
    std::cin >> n;              //we ask for a number
    std::cout << adder(n);      //we print the return value

    return 0;
}

int adder(int addNumber)        //counting function
{
    if (addNumber <= 1) {
        return 1;               //base case
    } else {
        return (addNumber + adder(addNumber - 1)); //we gave a recursion function to the return value
    }
}