#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `ai`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Print the sum of the elements in `ai`
    int a[] = {3, 4, 5, 6, 7};
    int sum = 0;
    int size = sizeof(a)/ sizeof(a[0]);
    for (int i = 0; i < size; ++i) {
        sum = sum + a[i];
    }
    std::cout << sum << std::endl;

    return 0;
}