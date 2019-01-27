#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> appendA(std::vector<std::string> savanna)
{
    std::vector<std::string> changedAnimals; //We create a vector typed string to fill with the elements of the original vector
    for (unsigned int i = 0; i < savanna.size(); i++) {
        changedAnimals.push_back(savanna[i]); //We fill new vector with x.push_back command
        changedAnimals[i] = changedAnimals[i] + "a"; //And give an "a"letter to each element
    }

    return changedAnimals;
}

int main(int argc, char *args[]) {
    std::vector<std::string> animals = {"bo", "anacond", "koal", "pand", "zebr"};

    // Create a function called "appendA()" that adds "a" to every string in the "animals" list.
    // The parameter should be a vector.

    std::vector<std::string> newAnimals = appendA(animals);

    for (int i = 0; i < newAnimals.size(); ++i) {
        std::cout << newAnimals[i] << " ";
    }

    return 0;
}