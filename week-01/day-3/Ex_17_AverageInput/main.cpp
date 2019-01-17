#include <iostream>

int main(int argc, char* args[]) {
    int a, b, c, d, e;

    // Write a program that asks for 5 integers in a row,
    std::cout << "Write 5 integers in a row: \n" << std::endl;
    // then it should print the sum and the average of these numbers like:
    std::cin >> a >> b >> c >> d >> e;
    int Sum = (a+b+c+d+e);
    float Aver = Sum/5.;
    // Sum: 22, Average: 4.4

    std::cout << "Sum: " << Sum << ", Average: " <<  Aver;

    return 0;
}