#include <stdio.h>
#include <stdlib.h>

//static
int * fun()
{
  static arr[5] = {1, 2, 3, 4, 5};
  return arr;
}

//heap
int * fun2()
{
  int * arr = (int*)malloc(5 * sizeof(int)); //az (*int) a pointer typecasing
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 3;
  arr[4] = 4;
  return arr;
}
int main() {
  //static
  int* ret_val = fun(); //ha azt akarom, hogy megmaradjon, akkor static-ot használok, nem szűnik meg a visszatérési érték.
  printf("%d\n", ret_val[4]);

  //heap
  int* ret_val2 = fun2();
  printf("%d\n", ret_val2[4]);
  realloc(ret_val2, 10 * sizeof(int));
  printf("%d\n", ret_val2[8]);

  //realloc(ret_val2, 0); //ha az adott memóriacím felszabadítását akarom elvégezni, így is tudom

  free(ret_val2);//it kell, mert a main hívta és itt hívta a heap-et

  int* another_array = (int*)calloc(10, sizeof(int));
  free(another_array);

  return 0;
}