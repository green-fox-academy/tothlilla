#include <iostream>
#include <string>

//Create a BlogPost class that has
// -an authorName
// -a title
// -a text
// -a publicationDate

// Create a few blog post objects:
// -"Lorem Ipsum" titled by John Doe posted at "2000.05.04."
//    -Lorem ipsum dolor sit amet.
// -"Wait but why" titled by Tim Urban posted at "2010.10.10."
//    -A popular long-form, stick-figure-illustrated blog about almost everything.
// -"One Engineer Is Trying to Get IBM to Reckon With Trump" titled by William Turton at "2017.03.28."
//    -Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention.
//    When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn’t really
//    into the whole organizer profile thing.
class Blogspot
{
public:
    void set_allthings(std::string au, std::string ttl, std::string txt, std::string date) { //Create the function used by the Postit class

        authorName = au; //First method
        title = ttl; //Second method
        text = txt; //Third method
        publicationDate = date; // Fourth method
        all =  "\"" + title + "\" titled by "  + authorName + " posted at \"" + publicationDate + "\"\n\t- "+ text;
        //all.append("\"").append(title).append("\"").append(" titled by ").append(authorName).append(" posted at ").append("\"").append(publicationDate).append("\" \n").append(text);
    }

    std::string getText(){
        return all;
    }


private:
    std::string authorName; //First variable
    std::string title; //Second variable
    std::string text; //Third variable
    std::string publicationDate; //Fourth variable
    std::string all;
};
int main(){

    std::string authorName1 = "John Doe";
    std::string title1 = "Lorem Ipsum";
    std::string text1 = "Lorem ipsum dolor sit amet";
    std::string publicationDate1 = "2000.05.04.";


    Blogspot oneText; //First object
    oneText.set_allthings(authorName1, title1, text1, publicationDate1);
    std::cout << oneText.getText()<< std::endl;

    std::string authorName2 = "Tim Urban";
    std::string title2 = "Wait but why";
    std::string text2 = "A popular long-form, stick-figure-illustrated blog about almost everything";
    std::string publicationDate2 = "2010.10.10.";


    Blogspot twoText; //Second object
    twoText.set_allthings(authorName2, title2, text2, publicationDate2);
    std::cout << twoText.getText()<< std::endl;

    return 0;
}