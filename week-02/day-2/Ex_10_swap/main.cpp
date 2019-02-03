#include <iostream>
void swap(int* aPrt, int* bPrt);

int main ()
{
  // Create a function which swaps the values of 'a' and 'b'
  // This time use a void funtion and pointers

  int a = 10;
  int b = 316;

  std::cout << a << " " << b << std::endl;
  int* aPrt = &a;
  int* bPrt = &b;
  swap(aPrt, bPrt);
  std::cout << a << " " << b << std::endl;

  return 0;
}

void swap(int* aPrt, int* bPrt)
{
  int temp;
  temp = *aPrt;
  *aPrt = *bPrt;
  *bPrt = temp;
}