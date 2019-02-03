#include <iostream>
#include <fstream>
#include <string>

int countline (std::string filename)
{
    std::ifstream myfile (filename);
    std::string text;
    int numLines = 0;
    if(myfile.is_open()){
        while(std::getline(myfile, text)){
            numLines+=1;
        }
        return numLines;
    } else {
        return 0;
    }
}

int main ()
{
    std::string name;
    std::cout << "Write the file name :" << std::endl;
    std::cin >> name;

    std::cout << countline(name) << std::endl;

    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    return 0;
}