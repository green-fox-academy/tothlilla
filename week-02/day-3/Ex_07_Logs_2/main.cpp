#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

// Read all data from 'log.txt'.
  // Each line represents a log message from a web server
  // Write a function that returns an array with the unique IP adresses.
  // Write a function that returns the GET / POST request ratio.
std::vector<std::string> IPadress(std::string path);
std::string ratio(std::string path);
int main() {

    std::string path = "log.txt";
    std::vector<std::string> uniqueAddress = IPadress(path);
    for (int i = 0; i < uniqueAddress.size(); ++i) {
        std::cout << uniqueAddress[i] << std::endl;
    }
    std::cout << ratio(path);


    return 0;
}
std::vector<std::string> IPadress(std::string path)
{
    std::ifstream myFile(path);
    try {
        if (!myFile.is_open()) {
          throw std::string("Openning error");
        }
    } catch (std::string &e) {
        std::cout << e;
    }
    std::vector<std::string> IPadressVector;
    std::string line;
    while (std::getline(myFile, line)){
        std::istringstream ss(line);
        std::string words;
        int counter = 0;
        while(std::getline(ss, words, ' ')){
            if (counter == 8){
                if (std::find(IPadressVector.begin(), IPadressVector.end(), words) == IPadressVector.end()){
                  IPadressVector.push_back(words);
                }
            }
            counter++;
        }
    }
    return IPadressVector;
}
std::string ratio(std::string path)
{
    std::ifstream myFile(path);
    try {
        if (!myFile.is_open()) {
            throw std::string("Openning error");
        }
    } catch (std::string &e) {
        std::cout << e;
    }

    std::string line;
    int counterPost = 0;
    int counterGet = 0;
    while (std::getline(myFile, line)) {
        std::istringstream ss(line);
        std::string words;
        int counter = 0;
        while (std::getline(ss, words, ' ')) {
            if (counter == 11) {
                if (words == "POST") {
                    counterPost++;
                } else {
                    counterGet++;
                }
            }
            counter++;
        }
    }
    return std::to_string(counterGet) + " / " + std::to_string(counterPost);
}


