#include <iostream>

int main(int argc, char* args[]) {

    int rightNumb;
    int guessNumb;
    std::cout <<"Write your number: " ;
    std::cin >> rightNumb;
    std::cout <<"Write your quess number: " ;
    std::cin >> guessNumb;


    while (rightNumb != guessNumb){
        if (rightNumb > guessNumb) {
            while (rightNumb > guessNumb) {
                std::cout << "The stored number is higher " << std::endl;
                std::cout << "Write next quess number: ";
                std::cin >> guessNumb;
            }
        } else {
            while (rightNumb < guessNumb) {
                std::cout << "The stored number is lover " << std::endl;
                std::cout << "Write next quess number: ";
                std::cin >> guessNumb;
            }
        }
    }

    std::cout <<"You found the number: " << guessNumb <<std::endl;


    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    return 0;
}