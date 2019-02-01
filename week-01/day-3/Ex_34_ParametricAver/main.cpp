#include <iostream>

int main(int argc, char* args[])
{

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4
    float numb;
    int sum = 0;
    std::cout << "Number of numbers :" << std::endl;
    std::cin >>  numb;
    for (int i = 0; i < numb ; ++i) {
        std::cout << "Print your numb :" << std::endl;
        int temp_sum;
        std::cin >>  temp_sum;
        sum = sum + temp_sum;
    }

  std::cout << "Sum: " << sum << " " << "Average: " << sum / numb << std::endl;
    return 0;
}