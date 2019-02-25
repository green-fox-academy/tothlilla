#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int number);
int equalOfDigits(int one, int two);
int main()
{
    int firstNum, secondNum;
    printf("Enter the first integer: \n");
    scanf("%d", &firstNum);
    printf("Enter the second integer: \n");
    scanf("%d", &secondNum);
    if (equalOfDigits(firstNum,secondNum)){
        printf("Holy shit\n");
    } else {
        printf("Damn\n");
    }

    return 0;
}

int sumOfDigits(int number)
{
    if (number < 10){
        return number;
    } else {
        int sum;
        while(number != 0) {
            sum = number % 10;
            number = number / 10;
        }
        return sum;
    }
}
int equalOfDigits(int one, int two) {


    return sumOfDigits(one) == sumOfDigits(two);

}
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0
