#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

int main ()
{
    printf("give me your full name and your age separate by space: \n");
    char storeArray[100] = "";
    gets(storeArray);

    char firstName[30];
    char lastName[30];
    int age;
    strcpy(firstName, strtok(storeArray," "));
    strcpy(lastName, strtok(NULL, " "));
    age = atoi(strtok(NULL, " "));
    printf("Your name is: %s %s and you are %d years old", firstName, lastName, age);

    return 0;
}