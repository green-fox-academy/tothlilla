#include <iostream>
#include <string>

//Create a PostIt class that has
// -a backgroundColor
// -a text on it
// -a textColor
//Create a few example post-it objects:
// -an orange with blue text: "Idea 1"
// -a pink with black text: "Awesome"
// -a yellow with green text: "Superb!"

class Postit
{
    public:
        Postit(std::string bgColor, std::string txtColor, std::string yourtext)
        {
            _backgroundColor = bgColor; //First method
            _textColor = txtColor; //Second method
            _text = yourtext; //Third method
        }
        void set_allthings (std::string bgColor, std::string txtColor, std::string yourtext) { //Create the function used by the Postit class
            std::cout << _backgroundColor << " " << _textColor << " " << _text << std::endl;

        }


    private:
        std::string _backgroundColor; //First variable
        std::string _textColor; //Second variable
        std::string _text; //Third variable

};


int main()
{

    Postit oneText("orange", "blue", "Idea 1"); //First object
    oneText.set_allthings("orange", "blue", "Idea 1");

    Postit twoText("pink", "black", "Avesome"); //Second object
    twoText.set_allthings("pink", "black", "Avesome");

    Postit threeText("yellow", "green", "Superb!"); //Third object
    threeText.set_allthings("yellow", "green", "Superb!");

    return 0;
}