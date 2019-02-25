#include <stdio.h>
#include "pi.h"

int main() {
    float radius;
    printf("Give me the radius: \n");
    scanf("%f", &radius);
    printf("area = %.2f\n", areaMeasure(radius));
  return 0;
}