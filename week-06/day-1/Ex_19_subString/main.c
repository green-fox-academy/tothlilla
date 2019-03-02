#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sub_string(char * str1, char * str2);

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same lenght than the function should return -1

    char * str1 = "abcde2fghi3jk4l";
    char * str2 = "2fga";

    printf("The result is %d", sub_string(str1, str2));

    return 0;
}
int sub_string(char * str1, char * str2)
{
  char *ret = strstr(str1, str2);
  int sizestr1 = strlen(str1) + 1;
  int sizestr2 = strlen(str2) + 1;
  if (sizestr1 == sizestr2){
      return  - 1;
  } else if (&ret != NULL){
      return 1;
  } else {
    return 0;
  }
}


