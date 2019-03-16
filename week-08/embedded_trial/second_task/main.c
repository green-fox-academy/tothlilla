#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{
	MANUAL,
	AUTOMATIC,
	CVT,
	SEMI_AUTOMATIC,
	DUAL_DUTCH

} transmission_t;
typedef struct
{
	char manufacturer_name[255]; //shorter than 256 characters
	float price_of_car; // in euros, stored as a floating point number
	int year_of_manufacture;
	transmission_t type_of_transmission; // as a custom type
} car_t;

int get_cars_older_than(car_t* cars, int array_length, int be_older_than);
int get_transmission_count(car_t* cars, int array_length, transmission_t transmission);
int main() {

	car_t list_of_cars[9];
	list_of_cars[0].year_of_manufacture = 5;
	list_of_cars[0].type_of_transmission = MANUAL;
	list_of_cars[1].year_of_manufacture = 7;
	list_of_cars[1].type_of_transmission = MANUAL;
	list_of_cars[2].year_of_manufacture = 7;
	list_of_cars[2].type_of_transmission = DUAL_DUTCH;
	list_of_cars[3].year_of_manufacture = 4;
	list_of_cars[3].type_of_transmission = SEMI_AUTOMATIC;
	list_of_cars[4].year_of_manufacture = 4;
	list_of_cars[4].type_of_transmission = CVT;
	list_of_cars[5].year_of_manufacture = 6;
	list_of_cars[5].type_of_transmission = SEMI_AUTOMATIC;
	list_of_cars[6].year_of_manufacture = 2;
	list_of_cars[6].type_of_transmission = MANUAL;
	list_of_cars[7].year_of_manufacture = 2;
	list_of_cars[7].type_of_transmission = CVT;
	list_of_cars[8].year_of_manufacture = 9;
	list_of_cars[8].type_of_transmission = AUTOMATIC;

	int be_older_than = 6;
	int array_length = 9;
	int number_of_older_than_cars = get_cars_older_than(list_of_cars, array_length, be_older_than);
	printf("%d\n", number_of_older_than_cars);

	transmission_t transmission = CVT;
	int number_of_cars_specic_transm = get_transmission_count(list_of_cars, array_length, transmission);
	printf("%d\n", number_of_cars_specic_transm);

	return 0;
}

int get_cars_older_than(car_t* cars, int array_length, int be_older_than)
{
	int number_of_older_cars = 0;
	for (int i = 0; i < array_length; ++i){
		if (cars[i].year_of_manufacture > be_older_than)
		{
			number_of_older_cars++;
		}
	}
	return number_of_older_cars;
}
int get_transmission_count(car_t* cars, int array_length, transmission_t transmission)
{
	int number_cars_with_transmission = 0;
	for (int i = 0; i < array_length; ++i){
		if (cars[i].type_of_transmission == number_cars_with_transmission)
		{
			number_cars_with_transmission++;
		}
	}
	return number_cars_with_transmission;
}