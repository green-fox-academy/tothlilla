#include <iostream>
#include <string>

void swap(int&, int&);

int main(int argc, char* args[]) {
    // Create two integer variables: a=15, b=23
    int a=15;
    int b=23;
    std::cout << a << "\n" << b << std::endl;
    swap (a,b);
    std::cout << a << "\n" << b << std::endl;
    // Create a function named swap that gets the 2 integers as parameters and swaps its values.
    // Print the values before and after the function call and make sure the values are printed in reversed order.

    return 0;
}
void swap(int& num1, int& num2){
    int c= 0;
    c = num2;
    num2 = num1;
    num1 = c;

}