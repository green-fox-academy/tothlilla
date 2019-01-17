#include <iostream>
#include <string>


/*
// - Create a string variable named `al` and assign the value `Greenfox` to it
std::string al = "Greenfox";

// - Create a function called `greet` that greets it's input parameter
void greet();

// - Greeting is printing e.g. `Greetings dear, Greenfox`
// - Greet `al`
int main(int argc, char* args[]) {
    greet();
    return 0;
}

void greet(){
    std::cout << "Greetings dear, " << al << std::endl;
}

 */
// - Create a string variable named `al` and assign the value `Greenfox` to it

// - Create a function called `greet` that greets it's input parameter
void greet(std::string);

// - Greeting is printing e.g. `Greetings dear, Greenfox`
// - Greet `al`
int main(int argc, char* args[]) {
    std::string x = "Greenfox";
    greet(x);
    return 0;
}

void greet(std::string al){
    std::cout << "Greetings dear, " << al << std::endl;
}