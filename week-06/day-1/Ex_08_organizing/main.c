//Continue working on the pi.c project
//Organise the function from the previous excercise to separate .c and .h files
//Create another function which calculates the circumference of a circle
//the radius of the circle should be passed as a parameter
//the function should return the calculated circumference
//circumference = 2 * radius * PI
//this function should be in the same .c and .h files as the one which calculates the area

#include <stdio.h>
#include "pi.h"



int main()
{
    float radius;
    printf("Give me the radius: \n");
    scanf("%f", &radius);
    printf("area = %.2f\n", areaMeasure(radius));
    printf("circumference = %.2f", circumferenceMeasure(radius));
    return 0;
}

