#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function
void sentenceSolutionOne(char string[]);
void sentenceSolutionTwo(char string[]);

int main()
{
    printf("Type a sentence:\n");
    char string[256];
    gets(string);
    printf("Type a sentence again:\n");
    char string2[256];
    gets(string2);
    printf("First solution: \n");
    sentenceSolutionOne(string);
    printf("Second solution: \n");
    sentenceSolutionTwo(string2); //nem működik
    return(0);
}

void sentenceSolutionOne(char string[])
{
    for (char *p = strtok(string, " "); p != NULL; p = strtok(NULL, " ")) {
        puts(p);
    }
}

void sentenceSolutionTwo(char string[])
{
    char *word = strtok(string, " ");
    while (word != NULL) {
        puts(word);
        word = strtok(NULL, " ");
    }
}
