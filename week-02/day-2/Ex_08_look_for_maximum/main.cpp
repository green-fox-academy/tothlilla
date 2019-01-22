#include <iostream>

int maximumnumb (const int examplearray[], int size){

    int miximaxi=examplearray[0];

    for (int i = 0; i < size; ++i) {

        if (miximaxi < examplearray[i]){
            miximaxi = examplearray [i];
        }

    }
    return miximaxi;
}

int main()
{
    int howMany;
    std::cout << "How many numbers want to compare?" << std::endl; // Create a program which first asks for a number
    std::cin >> howMany;     // this number indicates how many integers we want to store in an array
    std::cout << "Write your numbers :" << std::endl;

    int myArray[howMany];
    for (int i = 0; i < howMany; ++i) {
        std::cin >> myArray[i];     // and than asks for numbers till the user fills the array
    }
    int maxi = maximumnumb(myArray, howMany);
    int *prprprpr = &maxi;

    std::cout << maxi << "\n" <<prprprpr << std::endl;
    // It should print out the biggest number in the given array and the memory address of it

    return 0;
}