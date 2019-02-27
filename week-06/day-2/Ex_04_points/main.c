#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x;
    float y;
}point_t;

point_t create_point(float x_coordinate, float y_coordinate);

float distance(point_t object_one, point_t object_two);
/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
 */
int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
point_t create_point(float x_coordinate, float y_coordinate)
{
    point_t object;
    object.x = x_coordinate;
    object.y = y_coordinate;
    return object ;
}

float distance(point_t object_one, point_t object_two)
{
    float x_distance = object_one.x - object_two.x;
    float y_distance = object_one.y - object_two.y;
    float xy_distance = x_distance - y_distance;
    if (xy_distance < 0){
        xy_distance = xy_distance * (-1);
        return xy_distance;
    }
    return xy_distance;
}

