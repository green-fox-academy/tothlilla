#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main ()
{
  FILE * input_file;
  input_file = fopen("my-file.txt", "r");

  char file_line[200];
  while (!feof(input_file)){
    fgets(file_line, 200, input_file);
    printf("%s", file_line);
    //puts(fileLine);
  }
  return 0;
}