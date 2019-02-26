#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

void listPosition(char string[]);


int main ()
{
	char string[55] = "This is a string for testing";
	char *p;
	listPosition(string);

	return 0;
}

void listPosition(char string[])
{
    int positions = 0;
    //int positions = 1; //melyik a jó megoldás?
	for(char *p = strtok(string, "i"); p != NULL; p = strtok(NULL, "i")){
	    //printf("%d ",strlen(p)); //result: 2 2 7 11 2

	    positions += strlen(p);
	    printf("%d ", positions);
	}
}