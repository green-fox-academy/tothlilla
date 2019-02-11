#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> makingMatches(const std::vector<std::string>& girls, const std::vector<std::string>& boys)
{
    int moreMember;
    (girls.size() >= boys.size()) ? moreMember = girls.size() : moreMember = boys.size();
    std::vector<std::string> listMembers;

    for (int i = 0; i < moreMember; ++i) {
        if (i < girls.size()) {
            listMembers.push_back(girls[i]);
        }
        if (i < boys.size()) {
            listMembers.push_back(boys[i]);
        }
    }
    return listMembers;
}

int main(int argc, char* args[])
{
    std::vector<std::string> girls = {"Eve","Ashley","Claire","Kat","Jane"};
    std::vector<std::string> boys = {"Joe","Fred","Tom","Todd","Neef","Jeff"};

    // Write a method that joins the two lists by matching one girl with one boy into a new list
    // If someone has no pair, he/she should be the element of the list too
    // Exepected output: "Eve", "Joe", "Ashley", "Fred"...

    std::vector<std::string> matches =  makingMatches(girls, boys);

    for(int i = 0; i < matches.size(); ++i) {
        std::cout << matches[i] << " ";
    }

    return 0;
}