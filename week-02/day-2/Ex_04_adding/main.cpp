#include <iostream>

int main()
{
    // Add two numbers using pointers
    //First solution
    int a = 20;
    int b = 17;
    int c = a + b;
    int *p_c = &c;
    std::cout << *p_c << "\n" << c << "\n" << &c << std::endl;
    //Second solution
    int d = 20;
    int e = 17;
    int *p_d = &d;
    int *p_e = &e;
    int sum = *p_e + *p_d;
    std::cout << *p_d << "\n" << *p_e << "\n" << sum << std::endl;
    return 0;
}