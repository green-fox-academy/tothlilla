#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `s`
    //   with the following content: `[1, 2, 3, 8, 5, 6]`
    int s [] = {1, 2, 3, 8, 5, 6};
    // - Change the 8 to 4
    int c = 4;
    s[3] = c;
    // - Print the fourth element
    std::cout << s[3] << std::endl;

    return 0;
}