// I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
// Please fix it for me!
// Expected output: In a galaxy far far away

#include <iostream>
#include <string>

int main(int argc, char *args[]) {
    std::string example("In a dishwasher far far away"); //the original sentence.
    std::string need_word = "dishwasher"; //the word we want to change
    std::string changed_word = "galaxy";
    int start_replace = example.find(
            need_word); //Finding the index of changing word in the sentence, it should be integer.

    //example.replace(start_replace, need_word.length(), "galaxy"); //Usage of replace function with a string
    // necessary parameters: index of replacing word, and its length the next one; finished by the new string.
  example.replace(start_replace, need_word.length(), changed_word);
    std::cout << example << std::endl;
    return 0;
}
