/* #include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output
    int i, j;
    int howBig;
    std::cout << "How big the matrix is?" << std::endl;
    std::cin >> howBig;
    int** dimarray = new int*[howBig];
    for(int i = 0; i < howBig; ++i) {
        dimarray[i] = new int[howBig];
    }
    std::cout << "Write the row elements: " << std::endl;

    for (int i = 0; i < howBig; i++){
        for (int j = 0; j < howBig; j++) {

            std::cin >> dimarray[i][j];
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < howBig; ++i) {
        for (int j = 0; j < howBig; ++j) {
            std::cout << dimarray[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}
*/
#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int sizeOfMatrix;
    std::cout << "Please give me the size of the identity matrix" << std::endl;
    std::cin >> sizeOfMatrix;
    int identityMatrix[sizeOfMatrix][sizeOfMatrix];

    for (int i = 0; i < sizeOfMatrix; ++i) {
        for (int j = 0; j < sizeOfMatrix; ++j) {
            if (i == j) {
                identityMatrix[i][j] = 1;
            }else{
                identityMatrix[i][j] = 0;
            }
        }
    }
    for (int k = 0; k < sizeOfMatrix; ++k) {
        for (int l = 0; l < sizeOfMatrix; ++l) {
            std::cout << identityMatrix[k][l] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}