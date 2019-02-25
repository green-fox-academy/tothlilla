#include <stdio.h>
#include <stdlib.h>
#define PI 3.14
#define AREA(radius) (radius * radius * PI)


// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

int main()
{
    float area, radius;
    printf("Give me the radius: \n");
    scanf("%f", &radius);
    printf("area = %.2f", AREA(radius));

	return 0;
}