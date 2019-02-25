#include <stdio.h>
#include <stdlib.h>
#include "oddOrEven.h"

int main()
{
    int number;
    printf("Enter a number to even or odd: \n");
    scanf(" %d", &number);
    int result = ODDOREVEN(number);
    if (result){
      printf("It is even");
    } else {
      printf("It is odd");
    }
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    return 0;
}