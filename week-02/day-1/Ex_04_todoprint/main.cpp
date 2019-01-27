#include <iostream>
#include <string>


int main(int argc, char *args[]) {
    std::string todoText = " - Buy milk\n";

    // Add "My todo:" to the beginning of the todoText
    // Add " - Download games" to the end of the todoText
    // Add " - Diablo" to the end of the todoText but with indentation

    // Expected outpt:

    // My todo:
    //  - Buy milk
    //  - Download games
    //      - Diablo


    std::string todoBegin = "My todo:\n"; //Giving string before todoText variable
    std::string todoEnd = " - Download games\n\t - Diablo"; //Giving string after todoText variable, \t is a tabulator

    todoText.insert(0, todoBegin, 0, todoBegin.length()); // Add "My todo:" to the beginning of the todoText
    //Usage of insert function:
    //First the beginning index, second the new part (as a string),
    //third is the beginning index of new part you need to insert, the last is the closing index of new part you need to insert

    todoText.insert(todoText.length(), todoEnd, 0, todoEnd.length());
    //Usage of insert function:
    //First the beginning index, second the new part (as a string),
    //third is the beginning index of new part you need to insert, the last is the closing index of new part you need to insert


    //todoText.append(todoEnd); így is működik

    std::cout << todoText << std::endl; //Printing new string

    return 0;
}