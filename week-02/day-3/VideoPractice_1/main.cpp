#include <iostream>
#include <fstream>

//Ha ki akarod próbálni, akkor az .exe file-t használd!!!
//Ha ki akarod próbálni, akkor az .exe file-t használd!!!
//Ha ki akarod próbálni, akkor az .exe file-t használd!!!
//Ha ki akarod próbálni, akkor az .exe file-t használd!!!
//Ha ki akarod próbálni, akkor az .exe file-t használd!!!
//Ha ki akarod próbálni, akkor az .exe file-t használd!!!
int main()
{
  std::ofstream myFile("tuna.txt");
  std::cout << "Enter your ID, name, and money, " << std::endl;
  std::cout << "Dont't forget press CTRL+Z to quit: " << std::endl;
  int numb;
  std::string name;
  double money;
  while (std::cin >> numb >> name >> money){
    myFile << numb << " " << name << " " << money << std::endl;
  }

  myFile.close();
  return 0;
}