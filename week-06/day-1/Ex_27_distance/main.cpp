#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'
int stringsDistance(char str[]);

int main ()
{
    char str[] = "This is a sample string";
    //Checking before functon calling
    printf("%s\n", str);
    //Fuction calling
    printf("%d\n", stringsDistance(str));
    //Checking after functon calling
    printf("%s\n", str);
    return 0;
}

int stringsDistance(char str[])
{
    int temp_size = strlen(str) + 1;
    char temp[temp_size];
    strcpy(temp,str); //copy the original string to tokenizing
    char *first = strtok(temp, "s");
    int firstOccurence = strlen(first);
    int lastOccurence = 0;
    for (char *last = strtok(str, "s"); last != NULL; last = strtok(NULL, "s")) {
      //printf("'%s'\n", last); //Checking the tokenizing
      lastOccurence += strlen(last);
    }
    return (lastOccurence - 3 - firstOccurence);
}
