#include <iostream>

// Given a non-negative int n, return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while
// divide (/) by 10 removes the rightmost digit (126 / 10 is 12).


int sumDigit(int numberForDigit);       //predefinition of digits recursion function

int main() {
    std::cout << "Write a number :" << std::endl;
    int num;                      //1. the number of function calling, 2. the top number we want to add
    std::cin >> num;              //we ask for a number
    std::cout << sumDigit(num);      //we print the return value

    return 0;
}

int sumDigit(int numberForDigit)        //counting function
{
    if (numberForDigit < 10) {          //the base case value less than 10 because we works with decimal number system
        return numberForDigit;          //base case return
    } else {
        return (numberForDigit%10 + sumDigit(numberForDigit/10)); //we gave a recursion function to the return value
        //The first resursion value is the last local value (means 10 on the 0)
    }
}