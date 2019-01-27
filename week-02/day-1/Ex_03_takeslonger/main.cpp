#include <iostream>
#include <string>

// When saving this quote a disk error has occured. Please fix itstr.
// Add "always takes longer than" to the quote between the words "It" and "you" using the replace function

int main(int argc, char *args[]) {
    std::string quote("Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.");
    //The original string
    std::string quote_need = "always takes longer than "; //The sting we want to insert
    std::string quote_to_it = "Hofstadter's Law: It ";


    quote.replace(quote_to_it.length(), 0, quote_need);
    //First is the index number - but not with x.find function because of spaces!!!
    // Next is the length of changing part, which is zero because we want to insert something, not delete it
    // Finished by new expression


    std::cout << quote << std::endl; //Printing of changed string
    return 0;
}