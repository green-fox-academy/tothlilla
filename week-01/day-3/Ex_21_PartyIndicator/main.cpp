#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers
    // The first number represents the number of girls that comes to a party, the
    // second the boys
    int numbGirl, numbBoy;
    std::cout << "How many girls are there? " << std::endl;
    std:: cin >> numbGirl;
    std::cout << "How many boys are there? " << std::endl;
    std:: cin >> numbBoy;

    // It should print: The party is excellent!
    // If the the number of girls and boys are equal and 20 or more people are coming to the party
    //
    // It should print: Quite cool party!
    // If there are 20 or more people coming to the party but the girl - boy ratio is not 1-1
    //
    // It should print: Average party...
    // If there are less people coming than 20
    //
    // It should print: Sausage party
    // If no girls are coming, regardless the count of the people
    bool a = ((numbBoy + numbGirl) >= 20);
    bool b = (numbBoy == numbGirl);
    bool c = (numbGirl != 0);

    if (a && b) {
        std::cout << "The party is excellent!" << std::endl;
    } else if (a && !b && c) {
            std::cout << "Quite cool party!" << std::endl;
    } else if (!a && c) {
        std::cout << "Average party..." << std::endl;
    } else if (c != 1) {
        std::cout << "Sausage party" << std::endl;
    }

    return 0;
}