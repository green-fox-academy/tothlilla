#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {
    VOLVO,
    TOYOTA,
    LAND_ROVER,
    TESLA
};

struct car {
	enum car_type car_name;
	double km;
	double gas;
};
const char* get_car_name(enum car_type car_name)
{
    switch (car_name)
    {
        case VOLVO: return "Volvo";
        case TOYOTA: return "Toyota";
        case LAND_ROVER: return "Land Rover";
        case TESLA: return "TESLA";
    }
}
void stats_of_cars(struct car one_car);


int main()
{
	struct car volvo_car;
    volvo_car.car_name = VOLVO;
    volvo_car.km = 500000.00;
    volvo_car.gas = 6.7;
    stats_of_cars(volvo_car);

    struct car toyota_car;
    toyota_car.car_name = TOYOTA;
    toyota_car.km = 250000.00;
    toyota_car.gas = 5.7;
    stats_of_cars(toyota_car);

    struct car landrover_car;
    landrover_car.car_name = LAND_ROVER;
    landrover_car.km = 400000.00;
    landrover_car.gas = 9.8;
    stats_of_cars(landrover_car);

    struct car tesla_car;
    tesla_car.car_name = TESLA;
    tesla_car.km = 200000.00;
    stats_of_cars(tesla_car);

	return 0;
}

void stats_of_cars(struct car one_car)
{
    printf("%s drives %.2lf and its gas consuption is: ", get_car_name(one_car.car_name), one_car.km);
    if (one_car.car_name != TESLA) {
        printf("%.2lf.\n", one_car.gas);
    } else {
        printf("zero.\n");
    }
}