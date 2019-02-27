#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
  int* pointer_one = NULL;
  int* pointer_two = NULL;
  pointer_one = (int*)malloc(10 * sizeof(int));
  pointer_two = (int*)malloc(10 * sizeof(int));
  for (int i = 0; i < 10; ++i) {
      pointer_one[i] = i * 2 + 2;
      pointer_two[i] = i * 2 + 1;
  }


  for (int j = 0; j < 10; ++j) {
    printf("%d ", pointer_one[j]);
  }
  puts("\n------------");
  for (int k = 0; k < 10; ++k) {
    printf("%d ", pointer_two[k]);
  }

  pointer_two = (int*)realloc(pointer_two, 20 * sizeof(int));
  for (int l = 10; l < 20; ++l) {
    pointer_two[l] = pointer_one[l - 10];
  }
  puts("\n------------");
  for (int m = 19; m >= 0; --m) {
    printf("%d ", pointer_two[m]);
  }
  free(pointer_one);
  free(pointer_two);
  return 0;
}