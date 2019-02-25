// Write a program that stores 3 sides of a cuboid as variables (doubles)
// You should get these variables via console input
// The program should write the surface area and volume of the cuboid like:
//
// Surface Area: 600
// Volume: 1000
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double cuboidHeight, cuboidWidht, cuboidDeep;
    double surface, volume;
    printf("Enter the height: \n");
    scanf("%lf", &cuboidHeight);
    printf("Enter the widht: \n");
    scanf("%lf", &cuboidWidht);
    printf("Enter the deep: \n");
    scanf("%lf", &cuboidDeep);

    surface = 2 * (cuboidHeight * cuboidWidht + cuboidHeight * cuboidDeep + cuboidDeep * cuboidWidht);
    volume = cuboidHeight * cuboidWidht * cuboidDeep;
    printf("Surface Area: %.2lf\nVolume: %.2lf", surface, volume);

    return 0;
}