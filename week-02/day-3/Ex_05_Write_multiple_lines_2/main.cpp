#include <iostream>
#include <fstream>
#include <string>

  // Create a function that takes 3 parameters: a path, a word and a number
  // and is able to write into a file.
  // The path parameter should be a string that describes the location of the file you wish to modify
  // The word parameter should also be a string that will be written to the file as individual lines
  // The number parameter should describe how many lines the file should have.
  // If the word is "apple" and the number is 5, it should write 5 lines
  // into the file and each line should read "apple"

void writeMultiLines(std::string path, std::string word, int numb);

int main()
{
    std::string path ="../tuna.txt";
    std::string word = "apple";
    int numb = 5;
    writeMultiLines(path, word, numb);

    return 0;
}
void writeMultiLines(std::string path, std::string word, int numb) {
    std::ofstream myfile(path); //az ofstream mindig létrehoz egy file-t, ha nem létezik :D
    try {
        if (!myfile.is_open()){
          throw std::string("marmalade f*ck*p");
        }
    } catch (std::string &e){
        std::cout << e << std::endl;
    }

  for (int i = 0; i < numb; ++i) {
      myfile << word << "\n";
  }
}