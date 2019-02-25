#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char appendA(char str[]);

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string
    char str[15] = ""; //azért érdemes hosszúságot megadni, mert a hozzáfűzésekkel felülírom a memóriában meglévő adatokat
    printf("Type your string: ");
    gets(str);
    printf("The original string: %s\n", str);
    appendA(str);
    printf("The appended string: %s", str);
    return 0;

}

char appendA(char str[])
{
   char a[] = "a";
   strcat(str, a);
   return *str;
}