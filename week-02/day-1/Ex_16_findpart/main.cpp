#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> subInt (int paraNumb, std::vector<int> &paraVector)
{
    std::vector<int >::iterator findResult;
    std::vector<int >zerovector;


    for (findResult = paraVector.begin(); findResult < paraVector.end(); ++findResult) {

        if (findResult == paraVector.end()) {
            return zerovector;
        } else {
            zerovector.push_back(paraVector.at(paraNumb));

        }


    }
    return  zerovector;

}

int main(int argc, char* args[])
{
    //  Create a function that takes a number and a vector of numbers as a parameter
    //  Returns the indeces of the numbers in the vector where the first number is part of
    //  Returns an empty list if the number is not part any of the numbers in the vector

    //  Example:
    std::vector<int> numbers = {1, 11, 34, 52, 61};
    std::vector<int>newArray;
    subInt(1, numbers);
    //  should print: `[0, 1, 4]`
    subInt(0, numbers);
    //  should print: '[]'

    for (int i = 0; i < newArray.size() ; ++i) {
        newArray[i] = subInt(1, numbers);
        std::cout<< newArray[i];
    }

    return 0;
}