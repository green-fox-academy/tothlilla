/*
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

// Output: 1 2 3 4 5 6 7 8
    for(int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

// You can do it in reverse as well (note the differences between the loop headers!)
// Output: 8 7 6 5 4 3 2 1
    for(int i = numbers.size() - 1; i >= 0; --i) {
        std::cout << numbers[i] << " ";
    }
    return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> putSaturn(const std::vector<std::string>& planets){

    std::vector<std::string> listNewplanets;
    for (unsigned int i = 0; i < planets.size(); ++i) {
        listNewplanets.push_back(planets[i]);
    }

    listNewplanets.insert(listNewplanets.begin() + 5, "Saturn");
    return listNewplanets;

}

int main(int argc, char* args[]){

    std::vector<std::string> planets = {"Mercury","Venus","Earth","Mars","Jupiter","Uranus","Neptune"};

    // Saturn is missing from the planetList
    // Insert it into the correct position
    // Create a method called putSaturn() which has list parameter and returns the correct list.

    // Expected output: Mercury Venus Earth Mars Jupiter Saturn Uranus Neptune
    std::vector<std::string> correctPlanets = putSaturn(planets);

    for(int i = 0; i < correctPlanets.size(); ++i) {
        std::cout << correctPlanets[i] << " ";
    }



    return 0;
}