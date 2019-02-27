#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Create a smartphone register application
 * Read the content of smartphones.txt and store the informations in a structure called "smartphone:
 * - the name of the gadget (which is shorter than 256 characters) (Don't bother with the underscore('_') character, it's the part of the name)
 * - the year of the release (e.g. 2016)
 * - the type of the screen size (as a custom type, see below)
 *
 * In the file the size is given in cm but you should store the screen size type in an enumeration ("screen_size"),
 * the valid types are:
 *  - BIG -> (>= 15 cm)
 *  - MEDIUM -> (>= 12 cm)
 *  - SMALL -> (< 12 cm)
 *
 * The smartphones should be stored in an array.
 *
 * Implement the following functions:
 * - get_oldest_phone()
 *    - it should return the name of oldest device
 *    - it is up to you how your function declaration looks like (return type and arguments)
 * - get_screen_size_count()
 *    - it returns the count of phones which has "screen_size" size
 *    - it is up to you how your function declaration looks like (return type and arguments)
 *
 * Your main function should invoke these functions and print the following:
 * The ..... is the oldest device in the database
 * There are .... phones with BIG (>= 15 cm) screen size
 * There are .... phones with SMALL (< 12 cm) screen size
 *
 *
 * Additionally, you need to create a new file(prices.txt) that looks like this:
 * <NAME> <PRICE>
 * <NAME> <PRICE>
 * .
 * .
 * .
 *
 * To calculate the price use the following method. The base price of every phone is 300$.
 * If the size is SMALL, that adds 0$ to the value
 * If the size is MEDIUM, that adds 100$ to the value
 * If the size is BIG, that doubles the base price.
 *
 * The price also depends on the age. For every year that passed since its release,
 * the phone loses 50$ but the maximum value that it can lose because of the age is 250$
 */
//enum
enum screen_size{
  BIG,
  MEDIUM,
  SMALL
};
//transform an integer (size) into enum variable
enum screen_size get_screen_size(int size_cm)
{
  if (size_cm >= 15){
    return BIG;
  } else if (15 > size_cm && size_cm >= 12){
    return MEDIUM;
  } else {
    return SMALL;
  }
}
//making smartphone struct
typedef struct {
  char gadget[30];
  int year_of_release;
  enum screen_size one_size;
} smartphone_t;
//return the name of the oldest phone - we use object variables/member tags/members
char * get_oldest_phone(smartphone_t *array, int size) {
    //counter for the required index
    int index = 0; //we do this because index++ means index = index + 1
    //do this to compare every elements to every elements
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size; ++j) {
            if (array[index].year_of_release > array[j].year_of_release) {
                index++; //we step one index if value[index] bigger than the value of any elements behind the index
            }
        }
    }
    //return the name of an object at the necessary index
    return array[index].gadget;

}

int get_screen_size_count(smartphone_t *array, enum screen_size one_size, int size){
    int number_of_phones = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i].one_size == one_size){
            number_of_phones++;
        }
    }
    return number_of_phones;
}
void making_price_list(char path[], smartphone_t *array, int size)
{
    FILE * output_file;
    output_file = fopen(path, "w");
    if (output_file == NULL) {
        puts("Error");
        return;
    }

    int current_year = 2019;
    for (int i = 0; i < size; ++i) {
        int baseprice = 300;
        if (array[i].one_size == BIG){
            baseprice *= 2;
        }
        if (array[i].one_size == MEDIUM) {
            baseprice += 100;
        }
        int price_for_ages;
        price_for_ages = current_year - array[i].year_of_release;
        if((price_for_ages * 50) < 250) {
          baseprice = baseprice - (50 * price_for_ages);
        } else {
          baseprice -= 250;
        }
        fprintf(output_file, "%s %d\n", array[i].gadget, baseprice);
    }
    fclose(output_file);
}

int main()
{

    FILE * input_file;
    input_file = fopen("../phones.txt", "r");

    char single_line[50];
    smartphone_t array[15];
    int index = 0;
    while (!feof(input_file)){
        fgets(single_line, 50, input_file);
        smartphone_t object;
        strcpy(object.gadget, strtok(single_line, " "));
        object.year_of_release = atoi(strtok(NULL, " "));
        object.one_size = get_screen_size(atoi(strtok(NULL, " ")));
        array[index] = object;
        index++;
    }

    int size = sizeof(array)/ sizeof(array[0]);
    printf("The %s is the oldest device in the database\n", get_oldest_phone(array, size));
    printf("There are %d phones with BIG (>= 15 cm) screen size\n", get_screen_size_count(array, BIG, size));
    printf("There are %d phones with SMALL (< 12 cm) screen size\n", get_screen_size_count(array, SMALL, size));
    char path[] = "../prices.txt";
    making_price_list(path, array, size);
    for (int i = 0; i < size; ++i) {
      printf("%s %d %d\n", array[i].gadget, array[i].year_of_release, array[i].one_size);
    }
    fclose(input_file);
    return 0;
}