// Write a program that stores a number, and the user has to figure it out.
// The user can input guesses, after each guess the program would tell one
// of the following:
//
// The stored number is higher
// The stried number is lower
// You found the number: 8

#include<stdio.h>

int main()
{
    int guessnumb, tempNumb;
    printf("Enter your guessed number: \n");
    scanf("%d/n", &guessnumb); //don't use space after %d, because scanf() reads only the firs close character
    do{
        printf("Write a number :");
        scanf("%d/n", &tempNumb); //don't use space after %d, because scanf() reads only the firs close character
        if (tempNumb > guessnumb){
            printf("The stored number is lower.\n");
        } else if (tempNumb < guessnumb) {
            printf("The stored number is higher.\n");
        }
    } while (guessnumb != tempNumb);
    printf("You found the number: %d\n", tempNumb);
    return 0;
}
