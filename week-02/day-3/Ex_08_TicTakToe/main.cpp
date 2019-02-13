#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string ticTacResult(std::string path);

int main() {
    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    std::cout << ticTacResult("win-o.txt");
    // should print O
    std::cout << std::endl;
    std::cout << ticTacResult("win-x.txt");
    // should print X
    std::cout << std::endl;
    std::cout << ticTacResult("draw.txt");
    // should print draw
    std::cout << std::endl;
    return 0;
}
std::string ticTacResult(std::string path) {
  std::ifstream myfile(path);
  try {
    if (!myfile.is_open()) {
      throw std::string("Opening error");
    }
  } catch (std::string &e) {
    std::cout << e << std::endl;
  }
  std::string line;
  /*std::string temp;

  while(std::getline(myfile, line)){
      temp += line;
  }
  std::string result;
  if (temp[0] == temp[3] && temp[0] == temp[6]){
      result = temp[0];
      return result;
  } else if (temp[1] == temp[4] && temp[1] == temp[7]){
      result = temp[1];
      return result;
  } else if (temp[2] == temp[5] && temp[2] == temp[8]){
      result = temp[2];
      return result;
  } else if (temp[0] == temp[1] && temp[0] == temp[2]){
        result = temp[0];
      return result;
  } else if (temp[3] == temp[4] && temp[3] == temp[5]){
      result = temp[3];
      return result;
  } else if (temp[6] == temp[7] && temp[6] == temp[8]){
      result = temp[6];
      return result;
  } else if (temp[0] == temp[4] && temp[0] == temp[8]){
    result = temp[0];
    return result;
  } else if (temp[2] == temp[4] && temp[2] == temp[6]){
    result = temp[2];
    return result;
  } else {
      return "draw";
  }
*/

  std::vector<std::vector<char>> resultVector;
  std::string result;
  while (std::getline(myfile, line)) {
      std::vector<char> temp;
      temp.push_back(line[0]);
      temp.push_back(line[1]);
      temp.push_back(line[2]);
      resultVector.push_back(temp);
  }
  for (int i = 0; i < resultVector.size(); i++) {
      if (resultVector[i].at(0) == resultVector[i].at(1) && resultVector[i].at(0) == resultVector[i].at(2)) {
          result = resultVector[i].at(0);
          return result;
      } else if (resultVector[0].at(i) == resultVector[1].at(i) && resultVector[0].at(i) == resultVector[0].at(i)) {
          result = resultVector[0].at(i);
          return result;
      }
  }

  if (resultVector[0][0] == resultVector[1][1] && resultVector[0][0] == resultVector[2][2]) {
      result = resultVector[0][0];
      return result;
  } else if (resultVector[0][1] == resultVector[1][1] && resultVector[0][1] == resultVector[2][1]) {
      result = resultVector[0][1];
      return result;
  } else {
      return "draw";
  }

}