#include <iostream>

int refactorio(int n);

int main() {
  int number;
  std::cout << "Write a number to factor it: " << std::endl;
  std::cin >> number;
  std::cout << refactorio(number) << std::endl;
  return 0;
}

int refactorio(int n) {
    if (n == 0 || n == 1){
        return 1;
    } else {
        return n * refactorio(n - 1);;
    }
}