#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isSame(char strOne[], char strTwo[]);

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.
  char str1[15];
  char str2[15];

  strcpy(str1, "abcde7");
  strcpy(str2, "ABCDE7");
  if(isSame(str1, str2)){
      printf("Yes\n");
  } else {
      printf("No\n");
  }
  char str3[15];
  char str4[15];
  printf("Print to string with a space between eachother: ");
  scanf("%s %s", str3, str4);
  if(isSame(str3, str4)){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}

int isSame(char strOne[], char strTwo[])
{
  char tempCharOne[15];
  int sizeOne = strlen(strOne);
  for (int i = 0; i < sizeOne; ++i) {
      tempCharOne[i] = toupper(strOne[i]);
  }
  char tempCharTwo[15];
  int sizeTwo = strlen(strTwo);
  for (int i = 0; i < sizeTwo; ++i) {
    tempCharTwo[i] = toupper(strTwo[i]);
  }
  int ret;
  ret = strcmp(tempCharOne, tempCharTwo);

  return !ret;
}
