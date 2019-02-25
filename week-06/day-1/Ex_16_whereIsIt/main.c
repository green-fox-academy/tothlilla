#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int embedded(char str[], char findChar);

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    printf("Type your string: ");
    char str[50];
    char findChar;
    gets(str);
    printf("Type the character you want find: ");
    scanf("%c", &findChar);
    int result = embedded(str,findChar);
    printf("%d", result);

    return 0;
}

int embedded(char str[], char findChar)
{
  int len;
  len = strlen(str);
  for (int i = 0; i < len; ++i) {
      if (findChar == str[i]){
        return i;
      }
  }
  return -1;
}