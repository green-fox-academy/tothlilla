#include <iostream>
#include <string>
/*
    // - Create an integer variable named `baseNum` and assign the value `123` to it

    // - Create a function called `doubling` that doubles it's input parameter and returns with an integer
    void doubling(){
        int baseNum = 123;
        int a;
        a = baseNum*2;
        std::cout << a << std::endl;
    }

    // - Print the result of `doubling(baseNum)`
    int main (int argc, char* args[]){
        doubling();

        return 0;
    }  */

#include <iostream>
#include <string>
int doubling(int);
int main(int argc, char* args[]) {
    int baseNumb = 123;
    int a = doubling(baseNumb);
    std::cout << a << std::endl;
    return 0;
}

int doubling(int baseNum) {
    return baseNum*2;
}