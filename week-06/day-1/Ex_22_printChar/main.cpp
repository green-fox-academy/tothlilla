#include <stdio.h>
#include <stdlib.h>


// Modifiy this program to print out the number we want

int main()
{

    printf("%c\n", 65);
    printf("%d\n", 65);

    long ret;
    char str[] = "65";
    ret = strtol(str, nullptr, 10);
    printf("%d\n", ret);

    return 0;
}