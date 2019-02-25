#include <stdio.h>
#include <stdlib.h>
#include "oldEnough.h"


int main()
{
    int age;
    printf("Enter your age: ");
    scanf(" %d", &age);
    if(OLDENOUGH(age)){
        printf("Enough old");
    } else {
        printf("Not enough old");
    }

    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    return 0;
}

