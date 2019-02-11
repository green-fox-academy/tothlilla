#include <iostream>
struct twoNumb
{
  int a;
  int a2;
  float b;
};

int main() {
  twoNumb nums;
  nums.a = 5;
  nums.a2 = 6;
  nums.b = 8.3;

  twoNumb* p_nums = &nums; //pointerrel rállok a meglévő nums -ot, csak a memória helyet jeöli
  (*p_nums).a = 6; // ez a kettő ugyanaz!!!!!!
  p_nums->a2 = 7;// ez a kettő ugyanaz!!!!!! a nyíl kiváltaja a deference-et
  std::cout << "Hello, World!" << std::endl;
  return 0;
}