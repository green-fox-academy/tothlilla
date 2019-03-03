#include <string.h>
#include <stdio.h>
enum transmission {
  MANUAL,
  AUTOMATIC,
  CVT,
  SELF_AUTOMATIC,
  DUAL_CLUTCH
} transmission;

struct car
{
  char manufacturer_name[255];
  int price;
  int year;
  enum transmission trnsm;
};
char * get_transmission_type(enum transmission trnsm)
{
  if (trnsm == MANUAL){
    return "Manual";
  } else if (trnsm == AUTOMATIC){
    return "Automatic";
  } else if (trnsm == CVT){
    return "CVT";
  } else if (trnsm == SELF_AUTOMATIC){
    return "Self-automatic";
  } else if (trnsm == DUAL_CLUTCH){
    return "Dual-clutch";
  }
}
int get_older_cars_than(struct car* array, int array_length, int age)
{
  int car_counter = 0;
  for (int i = 0; i < array_length; ++i) {
    if (array[i].year > age){
      car_counter++;
    }
  }
  return car_counter;
}
int get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
{
  int car_counter = 0;
  for (int i = 0; i < array_length; ++i) {
    if (array[i].trnsm == trnsm){
      car_counter++;
    }
  }
  return car_counter;
}
/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

int main()
{
    struct car car_array[9];
    car_array[0].year = 5;
    car_array[0].trnsm = MANUAL;
    car_array[1].year = 7;
    car_array[1].trnsm = MANUAL;
    car_array[2].year = 7;
    car_array[2].trnsm = DUAL_CLUTCH;
    car_array[3].year = 4;
    car_array[3].trnsm = SELF_AUTOMATIC;
    car_array[4].year = 4;
    car_array[4].trnsm = CVT;
    car_array[5].year = 6;
    car_array[5].trnsm = DUAL_CLUTCH;
    car_array[6].year = 2;
    car_array[6].trnsm = MANUAL;
    car_array[7].year = 2;
    car_array[7].trnsm = CVT;
    car_array[8].year = 9;
    car_array[8].trnsm = AUTOMATIC;
    printf("Cars which are older than %d years are %d\n", 4, get_older_cars_than(car_array, 9, 4));
    printf("Cars which has %s transmission are %d\n", get_transmission_type(MANUAL), get_transmission_count(car_array, 9, MANUAL));
    return 0;
}