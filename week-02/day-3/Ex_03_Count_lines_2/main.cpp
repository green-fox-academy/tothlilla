#include <iostream>
#include <fstream>
#include <string>

int lineCounter(std::string fileName);
int main () {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file
    std::string filename = "tuna.txt";
    std::cout <<lineCounter(filename);
    return 0;
}
int lineCounter(std::string fileName)
{
    std::string line;
    int counter = 0;
    std::ifstream myfile(fileName);
    try {
        if (!myfile.is_open()){
          throw 0;
        }
    } catch (int x) {
        return x;
    }
    while (std::getline(myfile, line)){
        counter++;
    }
    myfile.close();
        return counter;

}