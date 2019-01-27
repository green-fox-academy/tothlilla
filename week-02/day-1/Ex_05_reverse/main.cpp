#include <iostream>
#include <string>

std::string reverse(const std::string &text)
{
    int size_text = text.length(); //Determind the lenght of original text
    std::string orig_expression = text; //Making a copy of original text we can rewrite
    std::string middle = ""; //Making a string independent from others
    int size_middle = middle.length(); ////Determind the lenght of independent text, which is 0 in the first round

    int size_orig_expression = orig_expression.length(); //We make independent the lenght of copy text from the original text

    for (unsigned int i = 0; i < size_text; i++) {
        middle.insert(size_middle, orig_expression, size_orig_expression - 1, 1);
        size_orig_expression = size_orig_expression - 1; //We need this to numbering be independent the origin text
        size_middle = size_middle + 1;
    }
    return middle;
}


int main(int argc, char *args[]) {
    std::string reversed = ".eslaf eb t'ndluow ecnetnes siht ,dehctiws erew eslaf dna eurt fo sgninaem eht fI";

    // Create a method that can reverse an std:string, which is passed as the parameter
    // Use it on this reversed string to check it!
    // Try to solve this using .at() first, and optionally anything else after.
    // Hint: You might use a temporary variable to swap 2 characters or you can use std::swap function.

    std::cout << reverse(reversed) << std::endl;

    return 0;
}