#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
int familyFriendlizer(std::string fileName, std::vector<std::string> offensiveWords);

int main()
{
  // There is a not so family friendly text in the `content.txt`
  // Create a function named familyFriendlizer that takes a filename and a list of strings as parameters
  // and remove all the given words from the file and returns the amount of the removed words.

  std::vector<std::string> offensiveWords = { "fuck", "bloody", "cock", "shit", "fucker", "fuckstick", "asshole", "dick", "piss" };

  std::cout << familyFriendlizer("content.txt", offensiveWords);

  return 0;
}

int familyFriendlizer(std::string fileName, std::vector<std::string> offensiveWords){
  std::ifstream inputFile;
  inputFile.open("content.txt");

  if (!inputFile.is_open()) {
    throw "File could not open";
  }
  std::string result;
  std::string stringStream;
  int removeWordCount = 0;

  std::string line;
  while (std::getline(inputFile, line)){
    std::stringstream stringStream(line);
    bool isOffensive = false;
    std::string word;
    while (std::getline(stringStream, word, ' ')){ // az elválasztott szavakat a word változóba rakjuk bele;
      for (int i = 0; i < offensiveWords.size(); ++i) {
        if (offensiveWords[i] == word){
          isOffensive = true;
          removeWordCount++;
          std::cout << word << std::endl;
          break;
        }
      }
      if (!isOffensive) {
        result += word + " ";
      }
    }

    //std::cout << line << std::endl;
  }

  inputFile.close();

  //std::ofstream outputFile;
  //outputFile.open(fileName);

  //outputFile << result; //ez kell a megoldáshoz csak kikommenteltem, hogy ne hajtsa végre
  //outputFile.close();
  std::cout << result << std::endl;
  //std::cout << removeWordCount << std::endl;

  return removeWordCount;

}