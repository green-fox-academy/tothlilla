#include <iostream>
#include <string>

std::string appendAFunc(std::string input);

int main(int argc, char* args[]){

    // - Create a string variable named `typo` and assign the value `Chinchill` to it
    std::string typo = "Chinchill";
    std::string result = appendAFunc(typo);

    // - Print the result of `appendAFunc(typo)`
    std::cout << result /*appendAFunc(typo)*/ <<std::endl;
    return 0;
}

// - Write a function called `appendAFunc` that gets a string as an input,
//   appends an 'a' character to its end and returns with a string
//
std::string appendAFunc(std::string input){
    return (input+"a");
}