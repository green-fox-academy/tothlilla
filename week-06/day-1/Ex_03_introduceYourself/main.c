#include<stdio.h>

int main()
{
    char name[20];
    int age;
    float height;

    printf("Type your name: ");
    scanf(" %s", name);
    printf("Type your age: ");
    scanf(" %d", &age);
    printf("Type your height: ");
    scanf("%f", &height);

    printf("My name is %s, and I am %d years old. My height is %.2f. metres.\n", name, age, height);
    printf("%s \n", name);
    printf("%d \n", age);
    printf("%.2f \n", height);
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87

    return 0;
}