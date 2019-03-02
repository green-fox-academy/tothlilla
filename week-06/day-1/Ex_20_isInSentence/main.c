#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int is_in_sentence(int *word, int *sentence);
int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return 1 if the given sentence contains the given word
    // and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "apple";
    char *sentence = "An Apple a day keeps the doctor away.";

    // the output should be: 1
    printf("The result is %d", is_in_sentence(&word, &sentence));

    return 0;
}
int is_in_sentence(int *word, int *sentence)
{
    int sizestr1 = strlen(*sentence) + 1;
    int sizestr2 = strlen(*word) + 1;
    char word_copy[sizestr2];
    char sentence_copy[sizestr1];

    //copy origingal string into a new array
    strcpy(word_copy, *word);
    strcpy(sentence_copy, *sentence);

    //checking the result of copy
    //printf("%s\n", word_copy); //checking the result of strcpy()
    //printf("%s\n", sentence_copy); //checking the result of strcpy()

    //modifying the copy strings by toupper()
    for (int i = 0; i <sizestr1 ; ++i) {
        sentence_copy[i] = toupper(sentence_copy[i]);
    }
    for (int i = 0; i <sizestr2 ; ++i) {
        word_copy[i] = toupper(word_copy[i]);
    }

    //checking the result of toupper()
    //printf("%s\n", word_copy); //checking the result of toupper()
    //printf("%s\n", sentence_copy); //checking the result of toupper()

    //making the comparision
    char *ret = strstr(sentence_copy, word_copy);
    if (sizestr1 == sizestr2){
        return  - 1;
    } else if (ret != NULL){
        return 1;
    } else {
        return 0;
    }
}