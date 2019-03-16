#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char final_letter_func(long int binary_code_as_integer_param)
{
	char c = binary_code_as_integer_param;
	return c;
}

char * final_text(char * path)
{
	FILE * input_file_prt;
	input_file_prt = fopen(path, "r");

	char binary_code_as_letter[9];
	long int binary_code_as_integer;
	char *binary_prt; //part of strtol function - not important
	char final_letter;
	char *final_song;
	final_song = (char*)calloc(sizeof(char), 2); //memory allocation to first char and the null terminate
	int i = 0;
	while(!feof(input_file_prt)){
		fscanf(input_file_prt, "%s", binary_code_as_letter), //fscan until the first 'white space'
		//printf("%s\n",binary_code_as_letter); //checking 9 bit long strings
		binary_code_as_integer = strtol(binary_code_as_letter, &binary_prt, 2); //convert string into decimal value, wether string would be a binary number
		//printf("%ld\n",binary_code_as_integer); //check long integer type values
		final_letter = final_letter_func(binary_code_as_integer);
		//printf("%c\n",final_letter); //check every char step by step
		final_song = (char*)realloc(final_song, strlen(final_song) + 1);
		final_song[i] = final_letter;
		i++;
		//printf("%s\n",final_song); //check the actual text of the song
	}
	fclose(input_file_prt);
	return final_song;
}
int main()
{
	char * path = "../../input.txt";
	char * text_end = final_text(path);
	printf("%s\n",text_end);
	free(text_end);
	return 0;
}