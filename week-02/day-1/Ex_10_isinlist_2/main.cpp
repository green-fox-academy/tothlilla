#include <iostream>
#include <vector>
#include <algorithm>

bool checkNums(const std::vector<int> &numbVector, const std::vector<int> &checkerVector)
{
    std::vector<int> temp;
    std::vector<int> tempChecker;
    for (unsigned int i = 0; i < numbVector.size(); ++i) {
        temp.push_back(numbVector[i]);
    }
    for (unsigned int i = 0; i < checkerVector.size(); ++i) {
        tempChecker.push_back(checkerVector[i]);
    }
    int checkerCounter = 0;
    for (int i = 0; i < tempChecker.size(); ++i) {
        if (std::find(temp.begin(), temp.end(), tempChecker[i]) != temp.end()){
                checkerCounter++;
        }
    }

    return (checkerCounter == tempChecker.size()) ? true : false;
}


int main(int argc, char* args[])
{
    const std::vector<int> numbers = {2, 4, 6, 8, 10, 12, 14};
    const std::vector<int> numbers2 = {2, 4, 6, 8, 10, 12, 14, 16};
    const std::vector<int> checker = {4, 8, 12, 16};

    // Check if vector contains all of the following elements: 4,8,12,16
    // Create a method that accepts vector as an input
    // it should return "true" if it contains all, otherwise "false"

    // Expected output: "The first vector does not contain all the numbers"
    if (checkNums(numbers, checker)) {
        std::cout << "The first vector contains all the numbers" << std::endl;
    } else {
        std::cout << "The first vector does not contain all the numbers" << std::endl;
    }

    // Expected output: "The second vector contains all the numbers"
    if (checkNums(numbers2, checker)) {
        std::cout << "The second vector contains all the numbers" << std::endl;
    } else {
        std::cout << "The second vector does not contain all the numbers" << std::endl;
    }

    return 0;
}