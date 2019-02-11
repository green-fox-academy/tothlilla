#include <iostream>
#include <string>
void outputArray(int myArray[],[][], int);

int main(int argc, char* args[]) {
    int size;
    int myArray[size][size]; // - Create (dynamically) a two dimensional array
    std::cin >> size;//   with the following matrix. Use a loop!
    outputArray(myArray, size);//   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output

    return 0;
}
void outputArray(int myArray[],[][], int size)
{
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (i == j) {
        myArray[i][j] = 1;
      } else {
        myArray[i][j] = 0;
      }
    }
  }
  for (int k = 0; k < size; ++k) {
    for (int i = 0; i < size; ++i) {
      std::cout << myArray[k][i] << " ";
    }
    std::cout << "\n";
  }

}