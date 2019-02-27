#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file
int count_lines(char file_name[]);

int main ()
{
    char file_name[] = "../my-file.txt";
    printf("%d",(count_lines(file_name)));
    return 0;
}
int count_lines(char file_name[])
{
    FILE * file_pointer;
    file_pointer = fopen(file_name, "r");

    if(file_pointer == NULL){
      return -1;
    }

    int counter = 0;
    char file_line[200];
    while(!feof(file_pointer)){
      fgets(file_line, 200, file_pointer);
      counter++;
    }
    fclose(file_pointer);
    return counter;
}