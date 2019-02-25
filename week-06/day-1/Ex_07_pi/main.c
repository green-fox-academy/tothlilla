#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

float areaMeasure(float radius);

int main()
{
    float radius;
    printf("Give me the radius: \n");
    scanf("%f", &radius);

    printf("%.2f", areaMeasure(radius));

	return 0;
}

float areaMeasure(float radius)
{
  float area;
  area = radius * radius * PI;
  return area;
}