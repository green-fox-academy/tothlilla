#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`
 /* funnnnnny!!!   int aj[] = {3, 4, 5, 6, 7};
    int size = sizeof(aj)/ sizeof(aj[0]);
    int d[size];
    int size2=size-1;

    for (int i = 0; i < size; ++i) {
        d[i] = aj [size2];
        aj [size2] = aj [i];
        aj [i] = d [i];
        size2= size2-1;
        std::cout << aj[i] << " ";
    }
*/
    int aj[] = {3, 4, 5, 6, 7};
    int size = sizeof(aj)/ sizeof(aj[0]);
    int d[size];
    int size2=size-1;

    for (int i = 0; i < size/2; ++i) {
        d[i] = aj[size2];
        aj[size2] = aj[i];
        aj[i] = d[i];
        size2 = size2 - 1;

    }
    for (int j = 0; j < size; ++j) {
        std::cout << aj[j] << " ";
    }

    return 0;
}