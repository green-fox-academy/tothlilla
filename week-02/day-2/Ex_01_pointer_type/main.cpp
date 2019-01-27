#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int* p_a = &a;
    double* p_b = &b;
    std::string* p_name = &name;
    *p_a = a;
    *p_b = b;
    *p_name = name;



    std::cout << p_a << "\n" << p_b << "\n" << p_name <<std::endl;
    std::cout << *p_a << "\n" << *p_b << "\n" << *p_name <<std::endl;

    return 0;
}