#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int* pointer = NULL;
    int number_x;
    printf("Give a number: \n");
    scanf("%d", &number_x);
    pointer = (int*)malloc(number_x * sizeof(int));
    printf("Give %d numbers\n", number_x);
    int index_for_y = 0;
    for (int i = 0; i < number_x; ++i) {
        printf("The %d. number: \n", i + 1);
        scanf("%d", &pointer[i]);
        index_for_y += pointer[i];
    }
    int *pointer_y = NULL;
    pointer_y = (int*)malloc(index_for_y * sizeof(int));

    for (int j = 0; j < index_for_y; ++j) {
        pointer_y[j] = j + 1;
    }
    for (int k = 0; k < index_for_y; ++k) {
        printf("%d ", pointer_y[k]);
    }
    puts("\n---------");
    //checking the X pointer array
    for (int i = 0; i < number_x; ++i) {
        printf("%d ", pointer[i]);
    }
    //checking the value of sum
    printf("\n%d\n", index_for_y);

    //dealloc pointers
    free(pointer);
    free(pointer_y);
    return 0;
}