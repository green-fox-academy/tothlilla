#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
std::vector<std::string> ipAddress(std::string fileName){
  std::ifstream myFile;
  myFile.open(fileName);
  std::string line;
  std::vector<std::string> myVector;
  while(std::getline(myFile, line)){
      std::istringstream ss(line);
      std::string expressions;
      int counter = 0;
      while (std::getline(ss, expressions, ' ')){
          if (counter == 8){
              if (std::find (myVector.begin(), myVector.end(), expressions) == myVector.end()){ // find végignézi elejétől a végéig
                //ha elmegy a végéig kilépés nélkül, akkor nem találta meg a kifejezést, ezért ozzá lehet fűzni a vector-hoz
                myVector.push_back(expressions);
              }
          }
        counter ++;
      }
  }
  myFile.close();
  return myVector;

}
std::string ratio(std::string fileName){
  std::ifstream myFile;
  myFile.open(fileName);
  std::string line;
  int counterGET = 0;
  int counterPOST = 0;
  while (std::getline(myFile, line)) {
      std::istringstream ss(line);
      std::string expressions;
      int counter = 0;
      while (std::getline(ss, expressions, ' ')) {
          if (counter == 11) {
              if (expressions == "GET") {
                counterGET++;
              } else if (expressions == "POST") {
                counterPOST++;
              }
          }
        counter++;
      }
  }
  myFile.close();
  return (std::to_string(counterGET) + "/" + std::to_string(counterPOST));

}

int main() {
  std::vector<std::string> printVector = ipAddress("log.txt");
  for (int i = 0; i < printVector.size(); ++i) {
    std::cout << i+1 << ": " << printVector[i] << std::endl;
  }
  std::cout << ratio("log.txt");


  return 0;
}