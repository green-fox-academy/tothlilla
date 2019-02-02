#include <iostream>
#include <string>
#include <bits/valarray_before.h>

int unique(int numbers[], int size);

int main(int argc, char* args[])
{
  //  Create a function that takes a list of numbers as a parameter
  //  Don't forget you have pass the size of the list as a parameter as well
  //  Returns a list of numbers where every number in the list occurs only once
  //  Example
  int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  std::cout << (unique(numbers, size)) << std::endl;
  //  should print: `[1, 11, 34, 52, 61]`
  return 0;
}

int unique(int numbers[], int size)
{
    int prev = 1;
    int uniqueCounter[prev - 1];
    for (int i = 0; i < size; ++i) {
        if (numbers[i] != numbers[prev]){
            uniqueCounter[i] = numbers[i];
            prev++;
        }
    }

    return uniqueCounter[prev];
}