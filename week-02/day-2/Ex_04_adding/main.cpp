#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int c = a + b;
    int *p_c = &c;



    std::cout << *p_c << "\n" << c << "\n" << &c << std::endl;

    return 0;
}