#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> makingMatches(const std::vector<std::string> &girls, const std::vector<std::string> &boys)
{

    std::vector<std::string> newvectorname; //We created a new vector typed string to be independent from original vector

    int need_size; //First time we don't know how many matches we will find, so girls or boys are more - we don't count them manually!!!
    if (girls.size() > boys.size()) {
        need_size = girls.size(); //If girls are more, the number of loops
    } else {
        need_size = boys.size(); //If boys are more, the number of loops
    }

    for (unsigned int i = 0;
         i < need_size; ++i) { //We use x.push_back to insert new element in a vector and resize them
        //We do the loop as many times as the number of bigger group is
        if (i < girls.size()) {
            newvectorname.push_back(girls[i]);
        }
        if (i < boys.size()) {
            newvectorname.push_back(boys[i]);
        }
    }

    return newvectorname;
}

int main(int argc, char *args[]) {

    std::vector<std::string> girls = {"Eve", "Ashley", "Claire", "Kat", "Jane"};
    std::vector<std::string> boys = {"Joe", "Fred", "Tom", "Todd", "Neef", "Jeff"};

    // Write a method that joins the two lists by matching one girl with one boy into a new list
    // If someone has no pair, he/she should be the element of the list too
    // Exepected output: "Eve", "Joe", "Ashley", "Fred"...

    std::vector<std::string> matches = makingMatches(girls, boys);

    for (int i = 0; i < matches.size(); ++i) {
        std::cout << matches[i] << " ";
    }

    return 0;
}