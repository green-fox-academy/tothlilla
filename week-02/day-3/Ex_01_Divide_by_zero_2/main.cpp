#include <iostream>
#include <fstream>
void zeroChecker(int numb);

int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0
    int yourNumb;
    std::cout << "Enter your numb: " <<std::endl;
    std::cin >> yourNumb;
    zeroChecker(yourNumb);
    return 0;
}
void zeroChecker(int numb)
{
    try {
        if (numb == 0){
            throw 0;
        }
        std::cout << 10 / numb;
    } catch(int x) {
        std::cout << "you cannot divide by " << x;
    }

}