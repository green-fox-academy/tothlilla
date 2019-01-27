#include <iostream>

int main ()
{
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;
    float *p_teperature = &temperature;

    temperature = 22.9;

    std::cout << *p_teperature <<std::endl;

    return 0;
}