#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int index_in_sentence(int *word, int *sentence);
int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return the index of the word in the sentence and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "doctor";
    char *sentence = "An apple a day keeps the doctor away jncq.";

    // the output should be: 6
    printf("The index of the word is %d", index_in_sentence(&word, &sentence));

    return 0;
}

int index_in_sentence(int *word, int *sentence)
{
  int sizestr1 = strlen(*sentence) + 1;
  int sizestr2 = strlen(*word) + 1;
  char word_copy[sizestr2];
  char sentence_copy[sizestr1];
  int return_index = 0;
  int bool = 0;
  //copy origingal string into a new array
  strcpy(word_copy, *word);
  strcpy(sentence_copy, *sentence);

  //modifying the copy strings by toupper()
  for (int i = 0; i <sizestr1 ; ++i) {
      sentence_copy[i] = toupper(sentence_copy[i]);
  }
  for (int i = 0; i <sizestr2 ; ++i) {
      word_copy[i] = toupper(word_copy[i]);
  }
  //finding the word
  for (int j = 0; j < sizestr1; ++j) {
      if (sentence_copy[j] == ' '){
          return_index++;
      } else if (sentence_copy[j] == word_copy[0]){
          bool = 1;
          int inner_counter = j;
          for (int i = 0; i < strlen(word_copy); ++i) {
              if (word_copy[i] != sentence_copy[inner_counter]){
                  bool = 0;
              }
              inner_counter++;
          }
          if (bool){
            return return_index;
          }
      }
  }
  return 0;
}