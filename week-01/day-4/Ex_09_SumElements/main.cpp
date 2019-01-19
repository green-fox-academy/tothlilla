#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `r`
    int r[]={54, 23, 66, 12};
    int rElementSum = r[1] + r[2];
    //   with the following content: `[54, 23, 66, 12]`
    // - Print the sum of the second and the third element
    std::cout << rElementSum << std::endl;

    return 0;
}