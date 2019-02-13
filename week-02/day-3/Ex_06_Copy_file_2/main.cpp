#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful
bool copySuccess(std::string origin, std::string copy);

int main()
{
  std::string origin = "origin.txt";
  std::string copy = "copy.txt";

  if (copySuccess(origin, copy)){
    std::cout << "It was successful!";
  } else {
    std::cout << "It wasn't successful!";
  }
  return 0;
}

bool copySuccess(std::string origin, std::string copy) {
  std::ifstream myFileOrigin(origin);
  std::ofstream myFileCopy(copy);
  std::string line;

  try {
    if (!myFileOrigin.is_open() && !myFileCopy.is_open()) {
      throw 0;
    }
  } catch (int x) {
    std::cout << "File opening error!";
  }

  while (std::getline(myFileOrigin, line)){
    myFileCopy << line << std::endl;
  }
  myFileCopy.close();
  myFileOrigin.close();
  std::ifstream copyFile(copy);
  std::ifstream originFile(origin);
  std::string originline;
  std::string copyline;
  while (std::getline(originFile, line)){
    std::getline(copyFile, line);
      if (originline != copyline){
        return false;
      }
  }
  originFile.close();
  copyFile.close();
  return true;
}
