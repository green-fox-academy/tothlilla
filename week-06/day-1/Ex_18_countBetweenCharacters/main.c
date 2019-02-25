#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(int * word);

int main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "Programming";

    // the output should be: 6 (in this case the repeating char was 'g')
    printf("%d\n", &word);// memóriacímet ad vissza (int)
    printf("%s\n", word);//stringet ad vissza
    printf("%d", count_between_chars(&word));

    return 0;
}

int count_between_chars(int * word)
{
    int indexFirst = 0;
    char doubledChar = 'g';
    char newArray[20];
    strcpy(newArray, *word);
    while(newArray[indexFirst] != doubledChar){
      indexFirst++;
    }
    int indexSecond = indexFirst + 1;
    while((newArray[indexSecond]) != doubledChar){
      indexSecond++;
    }
    return (indexSecond - indexFirst - 1);
}