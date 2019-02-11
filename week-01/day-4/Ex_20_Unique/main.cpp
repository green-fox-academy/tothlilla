#include <iostream>
#include <string>
void unique(int numbers[], int size){
  int tempNumbers;
  int newSize = 0;
  int tempArray[newSize];

  for (int i = 0; i < size; ++i) {
      tempNumbers = numbers [i];
    for (int j = i; j < size; ++j) {
      if (tempNumbers != numbers[j]){
        newSize ++;
        tempArray[i] = numbers[i];
      }
    }
  }
  for (int j = 0; j < newSize; ++j) {
    std::cout << tempArray[j] << " ";

  }
}
int main(int argc, char* args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    (unique(numbers, size));
    //  should print: `[1, 11, 34, 52, 61]`

    return 0;
}

