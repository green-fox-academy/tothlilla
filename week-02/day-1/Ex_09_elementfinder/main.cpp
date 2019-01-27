#include <iostream>
#include <vector>

std::string containsSeven(const std::vector<int> &numbers) {

    int size_numbers = numbers.size(); //Number of loops
    std::string hurray = "Hoorray"; //Output1
    std::string no = "Noooooo"; //Output2

    for (unsigned int i = 0; i < size_numbers; ++i) {
        if (numbers[i] == 7) { //Find the value
            return hurray; //Output1 in the loop
        }
    }

    return no; //Output2 outside the loop because it should return many times in a loop
}

int main(int argc, char *args[]) {
    const std::vector<int> numbers = {1, 2, 3, 4, 5};
    const std::vector<int> numbers2 = {6, 7, 8, 9, 10};

    // Write a method that checks if the vector contains "7" if it contains return "Hoorray" otherwise return "Noooooo"

    // Expected output: "Noooooo"
    std::cout << containsSeven(numbers) << std::endl;

    // Expected output: "Hoorray"
    std::cout << containsSeven(numbers2) << std::endl;

    return 0;
}
