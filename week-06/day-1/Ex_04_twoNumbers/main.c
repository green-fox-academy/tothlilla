#include<stdio.h>

int main()
{
    int a = 22;
    int b = 13;
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22
    printf("Print the result of 13 added to 22\n");
    printf("%d \n", a + b);
    int c = a + b;
    printf("%d \n", c);

    // Print the result of 13 substracted from 22
    printf("Print the result of 13 substracted from 22\n");
    printf("%d \n", a - b);
    int d = a - b;
    printf("%d \n", d);

    // Print the result of 22 multiplied by 13
    printf("Print the result of 22 multiplied by 13\n");
    printf("%d \n", b * a);
    int e = a * b;
    printf("%d \n", e);

    // Print the result of 22 divided by 13 (as a decimal fraction)
    printf("Print the result of 22 divided by 13 (as a decimal fraction)\n");
    printf("%d \n", a / b);

    int f1 = a / b;
    printf("%d \n", f1);
    printf("%.2f \n", f1); //ez hülyeséget ad vissza

    float f2 = a / b;
    printf("%.2f \n", f2); //ez int-et konvertál float-tá

    float f3 = (float)a / b; //ez az igazi float
    printf("%.2f \n", f3);


    // Print the reminder of 22 divided by 13
    printf("Print the reminder of 22 divided by 13\n");
    printf("%d\n", a % b);
    int g = a % b;
    printf("%d\n", g);

    // Store the results in variables and use them when you display the result

    return 0;
}