#include <iostream>
#include <string>

int main(int argc, char *args[]) {
    // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and not "bots"
    // Also, the URL is missing a crucial component, find out what it is and insert it too!

    std::string url("https//www.reddit.com/r/nevertellmethebots"); //The original string
    std::string need_expression = "bots"; //The part of the the string we want to change
    std::string new_expression = "odds";
    int start_replace = url.find(need_expression);
    //Determinding the beginning index of the changing word with x.find function
      url.replace(start_replace, need_expression.length(), "odds"); //Replacing original part with expression "odds"
    //First is the index number, next is the length of changing part, finished by new expression

    std::string need_expression2 = "//";
    std::string new_expression2 = ":"; //The string of new part
    //url.insert(5, new_expression2, 0, 1); //The method of inserting new parts in a string.
    //First the beginning index, second the new part (as a string),
    // third is the beginning index of new part you need to insert, the last is the closing index of new part you need to insert
    int start_insert = url.find(need_expression2);
    url.insert(start_insert, new_expression2, 0, new_expression2.length());

    std::cout << url << std::endl; //Printing of the new string

    return 0;
}