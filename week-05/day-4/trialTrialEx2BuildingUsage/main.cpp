#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include <map>
#include <algorithm>

void parseBuildingUsageData(std::string inputFileName, std::string outputFileName);


int main()
{
  //std::string input = "usage.txt";
  parseBuildingUsageData("../../usage.txt","" );


  std::cout << "Hello, World!" << std::endl;




  return 0;
}

void parseBuildingUsageData(std::string inputFileName, std::string outputFileName) {
  std::ifstream inputFile;
  inputFile.open(inputFileName);
  if (!inputFile.is_open()){ //ez egy exception
    throw "File could not be open!";
  }

  std::string name;
  std::string type;
  std::string date;

  std::map<std::string, int> usageData;

  while(inputFile >> name >> type >> date){
   usageData[type]++;
   //usageData[type] = +1;
  }
  inputFile.close();
  std::ofstream outputFile;
  outputFile.open(outputFileName);
  outputFile << "Building usage: "<<std::endl;

  for (std::map<std::string, int>::iterator it = usageData.begin(); it != usageData.end(); it++){
  //std::cout << "type: "<< it->first << ", number" << it->second<< std::endl;
    outputFile<< it->first << ":" << it->second<< std::endl;
}
}