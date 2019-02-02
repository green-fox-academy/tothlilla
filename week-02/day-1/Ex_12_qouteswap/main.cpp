// Accidentally I messed up this quote from Richard Feynman.
// Two words are out of place
// Your task is to fix it by swapping the right words with code
// Create a method called quoteSwap().
// Also, print the sentence to the output with spaces in between.
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> quoteSwap(std::vector<std::string> &origin, int size)
{
    //std::vector<std::string> temp;
    std::vector<std::string> swap = {" "};
    //  for (unsigned int i = 0; i < size; ++i) {
    //    temp.push_back(origin[i]);
    //}
    swap[0] = origin[2];
    origin[2] = origin[5];
    origin[5] = swap[0];

    return origin;
}


int main(int argc, char* args[])
{
    std::vector<std::string> quote = {"What", "I", "do", "create,", "I", "cannot", "not", "understand."};
    int size = sizeof(quote)/ sizeof(quote[0]);
    std::vector<std::string> rightQuote= quoteSwap(quote, size);

    for (int i = 0; i <quote.size() ; ++i) {
        std::cout << rightQuote[i] << " ";
    }
    return 0;
}