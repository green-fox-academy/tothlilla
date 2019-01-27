#include <iostream>
#include <vector>


bool checkNums(const std::vector<int> numb, const std::vector<int> check)
{

    std::vector<int> searcher;
    for (int i = 0; i < numb.size(); ++i) {      //Counting the elements of basic vector
        for (int j = 0; j < check.size(); ++j) { //Counting the elements of checker vector
            if (numb[i] == check[j]) {           //If we find a number in each vector...
                searcher.push_back(numb[i]);     //... we fill up with them a new vector
            }
        }
    }
    if (searcher.size() ==
        check.size()) {      //If the checker and the new vector size is equal, we find all the numbers
        return 1;
    } else {
        return 0;
    }


}

int main(int argc, char *args[]) {
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