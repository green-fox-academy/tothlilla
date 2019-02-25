#include <stdio.h>
#include <stdlib.h>

int equal(int one, int two);

int main()
{
    int one, two;
    printf("Enter two integers: ");
    scanf("%d", &one);
    scanf("%d", &two);
    if(equal(one,two)){
        printf("equal");
    } else {
        printf("not equal");
    }

    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    return 0;
}

int equal(int one, int two)
{
  return (one == two) ? 1 : 0;
}