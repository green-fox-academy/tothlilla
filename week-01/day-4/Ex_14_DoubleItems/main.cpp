#include <iostream>
#include <string>

int main(int argc, char* args[]) {
  // - Create an array variable named `numList`
  //   with the following content: `[3, 4, 5, 6, 7]`
  int numList [] = {3, 4, 5, 6, 7};
  int size = sizeof(numList) / sizeof(numList[0]);
  // - Double all the values in the array

      for (int i = 0; i < size; ++i) {
          numList[i] = numList[i] * 2;
      }
      for (int j = 0; j < size; ++j) {
          std::cout << numList[j] << " ";
      }
      std::cout << std::endl;

      return 0;
}
