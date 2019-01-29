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
        void set_allthings (int bgColor, int txtColor, std::string yourtext) { //Create the function used by the Postit class

            backgroundColor = bgColor; //First method
            textColor = txtColor; //Second method
            text = yourtext; //Third method
        }


    private:
        int backgroundColor; //First variable
        int textColor; //Second variable
        std::string text; //Third variable

};


int main() {

    Postit oneText; //First object
    oneText.set_allthings(orange, blue, "Idea 1");

    Postit twoText; //Second object
    twoText.set_allthings(pink, black, "Avesome");

    Postit threeText; //Third object
    threeText.set_allthings(yellow, green, "Superb!);

    return 0;
}