#include <stdio.h>
#include <stdlib.h>
int isItPrime(int number);
int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)
    int number;
    printf("Enter a positive integer: \n");
    scanf(" %d", &number);

    if(isItPrime(number)) {
      printf("%d is a prime number.", number);
    } else {
      printf("%d is not a prime number.", number);
    }

    return 0;
}

int isItPrime(int number) {
    if (number <= 1) {
        return 0;
    }
    int flag = 0;
    for (int i = 2; i < number / 2; i++) {
        if ((number % i) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        return 1;
    } else {
        return 0;
    }
}