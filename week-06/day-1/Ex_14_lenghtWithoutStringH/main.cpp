#include <stdio.h>
#include <stdlib.h>


int lenWithoutStringH(char stringOne[]);

int main()
{
    //Test section
    char stringOne[] = "Create a program which asks for the name of the user and stores it";
    int lenght = lenWithoutStringH(stringOne);
    printf("The lenght of this string is %d\n", lenght);
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    // Checker of test section
    printf("Check with sizeof(): %d\n", sizeof(stringOne)-1);

    //Length of string
    printf("Give your name: \n");
    char name[50];
    gets(name);
    printf("The lenght of your name is %d\n", lenWithoutStringH(name));
    return 0;
}
int lenWithoutStringH(char stringOne[])
{
    //int size = size_t(*stringOne) - 1; nem működik
    // int size = sizeof(stringOne); nem működik
    int size;
    for (size = 0; stringOne[size] != '\0'; size++);
    return size;
}