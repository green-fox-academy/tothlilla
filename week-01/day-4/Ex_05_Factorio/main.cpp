#include <iostream>
#include <string>

/*int factorio(int&);

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    int fact;
    std::cout << "Give a number: " << std::endl;
    std::cin >> fact;
    std::cout << factorio(fact) << std::endl;
    return 0;
}

int factorio(int& input){
    int klklkl = 1;

    for(int i = input;i>0;i--){
         klklkl *= i;
    }
    return klklkl;

}*/
#include <iostream>
#include <string>

void factorio(int, int&);

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    int fact;
    int akak;
    std::cout << "Give a number: " << std::endl;
    std::cin >> fact;
    factorio(fact, akak);
    std::cout << akak << std::endl;
    return 0;
}

void factorio(int input, int& output){
    int klklkl = 1;

    for(int i = input;i>0;i--){
         klklkl *= i;
    }
    output = klklkl;

}