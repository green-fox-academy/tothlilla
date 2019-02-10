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

  std::string line;
  std::ifstream whatUWant(firstFile);
  std::ofstream whereUWant(secondFile);
  try {

      if (!whatUWant.is_open()){
        throw 99;
      }
      if (!whereUWant.is_open()){
        throw 99;
      }
  } catch (int x) {
      return false;
  }
  while (std::getline(whatUWant, line)){
    whereUWant << line << std::endl;
  }
  //return linecounterOne == linecounterTwo;
  return true;

  whatUWant.close();
  whereUWant.close();
}