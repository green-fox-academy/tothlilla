#include <iostream>
#include <algorithm>
bool anagram(std::string input1, std::string input2) //two value to parameters - making copies
{
  std::sort(input1.begin(), input1.end()); //std::sort function belongs to <algorithm>, sort the first copy
  std::sort(input2.begin(), input2.end()); //std::sort function belongs to <algorithm>, sort the second copy
  if (input1.size() != input2.size()){ //first statement - they not be equal size
      return false;
  } else {
      for (int i = 0; i < input1.size(); ++i) { //counting the elements of both char[] until the end of them
          if (input1[i] != input2[i]){ //second statement - after sorting, the i-elements of both char[i] have not equal value
            return false;
          }
      }
  }
  return true; //any other case is true
}
int main() {
  std::string input1 = "dog";
  std::string input2 = "god";
  std::string input3 = "fox";
  std::string input4 = "green";
  std::cout << anagram(input1, input2) << std::endl;
  std::cout << anagram(input3, input4) << std::endl;

  return 0;
}