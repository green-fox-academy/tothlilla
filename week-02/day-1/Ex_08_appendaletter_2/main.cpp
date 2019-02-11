#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> appendA (std::vector<std::string> &animalVector);


int main(int argc, char* args[])
{
    std::vector<std::string> animals = {"bo", "anacond", "koal", "pand", "zebr"};

    // Create a function called "appendA()" that adds "a" to every string in the "animals" list.
    // The parameter should be a vector.

    std::vector<std::string> newAnimals = appendA(animals);

    for(int i = 0; i < newAnimals.size(); ++i) {
        std::cout << newAnimals[i] << " ";
    }

    return 0;
}
std::vector<std::string> appendA(std::vector<std::string> &animalVector)
{
  std::vector<std::string> temp;
  for(unsigned int i = 0; i < animalVector.size(); ++i) {
    temp.push_back(animalVector[i]);
    temp[i].append("a");
  }

  return temp;
}