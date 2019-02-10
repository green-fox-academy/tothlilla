#include <iostream>


int lookforvalue (int myarray[], int size,  int paranumb)
{
    int a;
    for (int i = 0; i < size ; ++i) {
        if (paranumb == myarray[i]){
            return i;
        } else {
            a = 0;
        }
    }
    return a;
}

int main()
{
    int parameter;
    int examplearray[6] = {1, 5, 9, 7, 8, 6};// Create a function which takes an array (and it's lenght) and a number as a parameter
    int size = sizeof(examplearray)/ sizeof(examplearray[0]);
    std::cout <<"Write a number from the array :" <<std::endl;
    std::cin >> parameter;
    int abcd =lookforvalue(examplearray, size, parameter);
    // the function should return index where it found the given value
    // if it can't find the number return 0
    std::cout << abcd <<std::endl;
    return 0;
}