#include <vector>
#include <iostream>

std::vector<std::vector<int>> rotateMatrix (std::vector<std::vector<int>> input);//most másolat készül
void printMatrix(const std::vector<std::vector<int>>& matrix);

int main()
{
  // Create a function named `rotateMatrix` that takes an n×n integer matrix (vector of vectors) as parameter
  // and returns a matrix which elements are rotated 90 degrees clockwise.
  //
  // example input:
  // [[1, 2, 3],
  // [4, 5, 6],
  // [7, 8, 9]]

  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  std::vector<std::vector<int>> rotatedMatrix = rotateMatrix(matrix);

  printMatrix(rotatedMatrix);
  // should print
  // 7 4 1
  // 8 5 2
  // 9 6 3

  return 0;
}

void printMatrix(const std::vector<std::vector<int>>& matrix)
{
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
std::vector<std::vector<int>> rotateMatrix(std::vector<std::vector<int>> input)
{
  std::vector<std::vector<int>> result = input; // a temp vectoromba bemásolom az eredeti mátrixot,
  // így az indexelése is átmegy, érték szerinti értékadás
  //ekkora memóriahelyet fogalalok neki

  for (int i = 0; i < input.size(); ++i) {
    //for (int j = 0; j < input[i].size(); ++j) { //ezt használom, ha nem négyzetről van szó, mert itt az aktuális sor méretét veszi ciklusnak

    //std::vector<int> row; 2. megoldás, de bonyolult
    for (int j = 0; j < input[i].size(); ++j) {
      result[i][j] = input[j][i]; // ez a legegyszerűbb mód és akkor nem hozom be a row változót!!!
      //ennél a lehetőségnél össze lehet vonni a következő résszel pl.: result[i][j] = input[input.size() - j - 1][i];
      //row.push_back(input[j][i]); 2. megoldás, de bonyolult
    }
    //result.push_back(row); 2. megoldás, de bonyolult
  }

  std::vector<std::vector<int>> finalresult = result;
  for (int i = 0; i < input.size(); ++i) {
    for (int j = 0; j < input.size(); ++j) {
      /*int centralindex = input[i].size()/2;
      int newindex = j; //ez azért, mert ha páratlan számú, akkor a középső megtartja az indexét!
      if (j > centralindex) {
        newindex = j - centralindex - 1;
      } else {
        newindex = j + centralindex +1;
      }
      finalresult[i][j] = result[i][newindex];*/

      finalresult[i][j] = result[i][input.size() - j - 1];
    }
  }

  return finalresult;
}
