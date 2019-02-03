#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful
bool copy(std::string firstFile, std::string secondFile);

int main()
{
  std::string firstFile;
  std::string secondFile;
  std::cout << "Write two filename :" << std::endl;
  std::cin >> firstFile >> secondFile;
  if (copy(firstFile, secondFile)){
    std::cout << "It was succesful";
  } else {
    std::cout << "It was not succesful";
  }
  return 0;
}
bool copy(std::string firstFile, std::string secondFile)
{
  std::ifstream whatUWant(firstFile);
  std::ofstream whereUWant(secondFile);
  std::string line;
  int linecounterOne = 0;
  int linecounterTwo = 0;
  while (std::getline(whatUWant, line)){
    whereUWant << line << std::endl;
    linecounterOne++;
    linecounterTwo++;
  }
  return linecounterOne == linecounterTwo;

  whatUWant.close();
  whereUWant.close();
}