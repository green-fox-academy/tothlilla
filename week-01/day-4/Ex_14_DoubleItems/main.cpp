#include <iostream>
#include <string>

int doublearray (int&);

int main(int argc, char* args[]) {

    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    int numList [] = {3, 4, 5, 6, 7};
    // - Double all the values in the array
    std::cout << doublearray(numList) <<std::endl;

    return 0;

}

int  doublearray (int& examplearray){
    int size = sizeof(examplearray)/sizeof(examplearray [0]);
    for (int i = 0; i < size; ++i) {
        int newarray[size];
        int middle;
        middle = 2 * examplearray[i];
        newarray[i]= middle;
        return newarray[size];
    }


}
/*
#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int numList[] ={3, 4, 5, 6, 7};
    for (int i = 0; i < sizeof(numList)/sizeof(numList[0]); ++i) {
        numList[i] = numList[i] * 2;
    }
    for (int j = 0; j < sizeof(numList)/sizeof(numList[0]); ++j) {
        std::cout << numList[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}
 */