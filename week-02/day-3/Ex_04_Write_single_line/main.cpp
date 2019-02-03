#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream lillaFile;
    lillaFile.open("my-file.txt");
    // Open a file called "my-file.txt"
    // Write your name in it as a single line
    lillaFile << "Lilla Toth";

    lillaFile.close();

    return 0;
}