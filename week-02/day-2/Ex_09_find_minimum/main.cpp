#include <iostream>

int *whichIsMin(int exampleArray[], int sizeExamplearray) {

    int *minNumberPtr = nullptr;
    int mini=exampleArray[0];
    for (int i = 0; i < sizeExamplearray; ++i) {

        if (mini > exampleArray[i]){
            minNumberPtr = &exampleArray[i];
            mini = exampleArray[i];
        }
    }
    return minNumberPtr;

}
int main(){
    int numbers[] = {12, 4, 66, 101, 87, 3, 15};     // Create a function which takes an array (and its length) as a parameter
    int size = sizeof(numbers)/sizeof(numbers[0]);    // and returns a pointer to its minimum value


    int minNumberPtr = *whichIsMin(numbers, size);

    std::cout << "The minimum number is: " << minNumberPtr << std::endl;
    std::cout << "The minimum number address: " << numbers+5 << std::endl;
    std::cout << "The minimum number address: " << whichIsMin(numbers, size) << std::endl;

    return 0;
}