// Create a function named `rotateMatrix` that takes an n×n integer matrix (vector of vectors) as parameter
// and returns a matrix which elements are rotated 90 degrees clockwise.
#include <iostream>
#include <vector>

/*std::vector<std::vector<int>> rotateMatrix(std::vector<std::vector<int>> zero)
{
  int tempnumb;
  std::vector<std::vector<int>> tempMatrix;
  for (int i = 0; i < zero.size(); ++i) {
    for (int j = 0; j < zero.size(); ++j) {
      tempMatrix[i][j] = zero[i][j];
    }
  }
  for (int i = 0; i < tempMatrix.size(); ++i) {
    for (int j = 0; j < tempMatrix.size(); ++j) {
      tempnumb = tempMatrix[i][j];
      tempMatrix [i][j] =  tempMatrix[j][i];
      tempMatrix[j][i] = tempnumb;
    }
  }
  for (int k = 0; k < tempMatrix.size(); ++k) {
      for (int i = 0; i < tempMatrix.size()/2; ++i) {
          tempnumb = tempMatrix [k][i];
          tempMatrix [k][i] = tempMatrix[i][k];
          tempMatrix[i][k] = tempnumb;

      }
  }
  return tempMatrix;
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
*/
int main() {
   std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

   /*std::vector<std::vector<int>> tempMainMatrix = rotatematrix(matrix);
  for (int i = 0; i < tempMainMatrix.size(); ++i) {
    for (int j = 0; j < tempMainMatrix.size(); ++j) {
      std::cout << tempMainMatrix[i][j];
    }
  }*/

  int tempnumb = 0;

  /*for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix.size(); ++j) {
      tempnumb = matrix[i][j];
      matrix [i][j] =  matrix[j][i];
      matrix[j][i] = tempnumb;

    }
  }*/

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix.size()/2; ++j) {
      tempnumb = matrix[i][j];
      matrix [i][j] =  matrix[i][matrix.size()-1-j];
      matrix[i][matrix.size()-1-j] = tempnumb;

    }
  }
  for (int i = 0; i < matrix.size()/2; ++i) {
    for (int j = 0; j < matrix.size(); ++j) {
      tempnumb = matrix[i][j];
      matrix [i][j] =  matrix[i][matrix.size()-1-j];
      matrix[i][matrix.size()-1-j] = tempnumb;

    }
  }

  for (int k = 0; k < matrix.size(); ++k) {
    for (int i = 0; i < matrix.size(); ++i) {
      std::cout <<  matrix[k][i] << " ";
    }
    std::cout << "\n";
  }
  //std::vector<std::vector<int>> rotatedMatrix = rotateMatrix(matrix);

  //printMatrix(rotatedMatrix);

  return 0;
}
