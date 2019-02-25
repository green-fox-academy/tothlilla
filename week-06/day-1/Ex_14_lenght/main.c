#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char stringOne[]);

int main()
{
    char stringOne[] = "Create a program which asks for the name of the user and stroes it";
    int lenght = len(stringOne);
    printf("The lenght of this string is %d.\n", lenght);
    char name[50];
    printf("Give your name: \n");
    gets(name);
    printf("The lenght of your name is %d.\n", len(name));

    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    return 0;
}
int len(char stringOne[])
{
    int lenghtOfString = 0;
    lenghtOfString = strlen(stringOne);

    return lenghtOfString;

}