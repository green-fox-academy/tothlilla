#include <iostream>
#include <vector>
std::vector<std::vector<int>> calculateMaxMatrix(std::vector<std::vector<int>> &input1, std::vector<std::vector<int>> &input2);

bool doesFirstTestPass()
{
  //arrange
  std::vector<std::vector<int>> firstInput = {{2, 1},{0, 1}};
  std::vector<std::vector<int>> secondInput = {{0, 3},{-1, 1}};

  //act
  std::vector<std::vector<int>> result =  calculateMaxMatrix(firstInput, firstInput);

  //assert
  std::vector<std::vector<int>> expected = {{2, 3},{0, 1}};
  return (result == expected);
}

bool doesSecondTestPass()
{
  //arrange
  std::vector<std::vector<int>> firstInput = {{2, 1, 3},{0, 1, 3},{5, 6, -5}};
  std::vector<std::vector<int>> secondInput = {{5, 0, 3},{-8,-1, 1},{6,7,8}};

  //act
  std::vector<std::vector<int>> result =  calculateMaxMatrix(firstInput, firstInput);

  //assert
  std::vector<std::vector<int>> expected = {{5, 1, 3},{0, 1, 3}, {6, 7, 8}};
  return (result == expected);

}

int main()
{
  std::cout << "First test result is: " << doesFirstTestPass()<< std::endl;
  std::cout << "Second test result is: " << doesSecondTestPass()<< std::endl;
  return 0;
}

std::vector<std::vector<int>> calculateMaxMatrix(std::vector<std::vector<int>> &input1, std::vector<std::vector<int>> &input2)
{
  std::vector<std::vector<int>> result;
  result.resize(input1.size()); //átméretezem, hogy akkora legyen, mint a paraméter mátrix
  for (int i = 0; i < input1.size(); ++i) {
    result[i].resize(input1[i].size()); //
    for (int j = 0; j < input2.size(); ++j) {
      if (input1[i][j] > input2[i][j]){
        result[i][j] = input1[i][j];
      } else{
        result[i][j] = input2[i][j];
      }
    }
  }
  //std::vector<std::vector<int>> result = input1; //így is el lehet kezdeni
  return result;
}