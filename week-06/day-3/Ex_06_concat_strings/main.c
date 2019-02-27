#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.
char * concat_strings(char * string_one, char * string_two)
{
  char * concatenated_string = (char*)calloc((strlen(string_one) + strlen(string_two) + 1), sizeof(char));
  //concatenated_string = (char*)malloc((strlen(string_one) + strlen(string_two) + 1) * sizeof(char));
  strcpy(concatenated_string,string_one);
  strcat(concatenated_string,string_two);
  return concatenated_string;
}
int first_test()
{
    //arrange
    char * string_one = "";
    char * string_two = "";
    //act
    char * test_string = {""};
    char * result_string = concat_strings(string_one, string_two);
    //assert
    int result_first_test = strcmp(result_string,test_string);
    return result_first_test;
}
int second_test()
{
    //arrange
    char * string_one = "blah blah ";
    char * string_two = "kismacska";
    //act
    char * test_string = "blah blah kismacska";
    char * result_string = concat_strings(string_one, string_two);
    //assert

    printf("Result of second test strcmp() function: %d\n",strcmp(result_string,test_string));
    int result_second_test = strcmp(result_string,test_string);

    printf("Size of test 2 string one : %d\n", strlen(string_one));
    printf("Size of test 2 string two : %d\n", strlen(string_two));
    printf("Size of test 2 test string : %d\n", strlen(test_string));
    return result_second_test;

}
int main()
{
    //test cases
    if (!first_test()){
        printf("test 1 is cool\n");
    } else {
        printf("test 1 is para\n");
    }
    if (!second_test()){
        printf("test 2 is cool\n");
    } else {
        printf("test 2 is para\n");
    }
    //main
    char * string_one = "this string ";
    char * string_two = "from the main()";
    int size_one = strlen(string_one);
    int size_two = strlen(string_two);
    //Checking the length of the original strings
    printf("\nLength of the first string is %d and the second string is %d in the main().\n", size_one, size_two);
    char * result = concat_strings(string_one, string_two);
    //Checking the result string
    printf("My result string from the main() is: %s\n", result);
    //Length of the result string
    int size_result = strlen(result);
    printf("The length of the result string is %d\n", size_result);



    free(result);
    return 0;
}