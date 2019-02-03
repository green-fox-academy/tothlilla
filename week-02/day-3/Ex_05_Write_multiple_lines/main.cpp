#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number,
// than it should write to a file.
// The path parameter should describes the location of the file.
// The word parameter should be a string, that will be written to the file as lines
// The number paramter should describe how many lines the file should have.
// So if the word is "apple" and the number is 5, than it should write 5 lines
// to the file and each line should be "apple"

void funkyFunc (std::string path, std::string wordToRepeat, int numRepeat)
{
    std::ofstream lillaFile(path);
    for (int i = 0; i < numRepeat; ++i) {
        lillaFile << wordToRepeat <<"\n";
    }
}

int main()
{
    std::string path;
    std::string word;
    int number;
    std::cout << "Enter the path of the file, a word and a number: ";
    std::cin >> path >> word >> number;
    funkyFunc(path, word, number);
    return 0;
}