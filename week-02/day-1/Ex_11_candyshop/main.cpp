#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<std::string>filter(std::vector<std::string> &list, const std::vector<std::string> &sweets)
{
  std::vector<std::string> tempList;
  std::vector<std::string> tempSweets;
  for (unsigned int j = 0; j < list.size(); ++j) {
      tempList.push_back(list[j]);
  }
  for (unsigned int j = 0; j < sweets.size(); ++j) {
      tempSweets.push_back(sweets[j]);
  }

    for (int i = 0; i < tempList.size(); ++i) {
       if (std::find(tempSweets.begin(), tempSweets.end(), tempList[i]) != tempSweets.end()){
           tempList.erase(tempList.begin() + i);
           i--; //azért kell csökkentenem a sorszámozást, mert a 2. tag törlése után a "Bread" nem a 3. tag, hanem a 2. helyre került
       }
    }
    return tempList;
}

int main(int argc, char* args[])
{
    const std::vector<std::string> sweets = {"Cupcake", "Brownie"};
    std::vector<std::string> list = {"Cupcake", "Carrot", "Bread", "Brownie", "Lemon"};

    // Accidentally we added "Carrot", "Lemon" and "Bread" to the list.
    // Your task is to remove them from the list. "sweets" vector can help you with this
    // You should erase every element from "list" vector that is not in "sweets" vector.
    // No, don't just remove the lines
    // Create a method called filter() which takes the two lists as parameters.

    std::vector<std::string> filteredList = filter(list, sweets);

    // Expected output: Cupcake Brownie
    for (int i = 0; i < filteredList.size(); ++i) {
        std::cout << filteredList[i] << " ";
    }

    return 0;
}