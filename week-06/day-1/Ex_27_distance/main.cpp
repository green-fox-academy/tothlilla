#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'
int stringsDistance(char str[]);

int main ()
{
    char str[] = "This is a sample string";
    //printf("%s", str); érdekes...
    //char *first, *last;
    printf("%d", stringsDistance(str));
    //printf("%s", str);
    return 0;
}

int stringsDistance(char str[])
{
    char temp[strlen(str)];
    strcat(temp,str); //muszáj vagyok betölteni az eredeti doksit valamibe, mert a *first-höz és a *last-hoz is kell darabolnom
    char *first = strtok(temp, "s");
    int firstOccure = strlen(first);

    int lastOccure = 0;
    for (char *last = strtok(str, "s"); last != NULL; last =strtok(NULL, "s")) {
      lastOccure += strlen(last);
    }
    return (lastOccure - firstOccure);
}
