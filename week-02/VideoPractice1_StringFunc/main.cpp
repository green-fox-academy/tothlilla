#include <iostream>
#include<string>
int main() {
  std::string input1;
  std::cout << "Enter your name: " << std::endl;
  std::cin >> input1; //csak az első zárókarakterig olvassa be a szöveget
  std::cout << "Hello, " << input1 << ", welcome to this tutorial." << std::endl;
  std::cout << std::endl;
//getline
  std::string input2;
  std::cout << "Enter your name: " << std::endl;
  std::getline(std::cin, input2); //átlép a string záró karaktereken és az első sorig (enter) olvassa a szöveget
  std::cout << "Hello, " << input2 << ", welcome to this tutorial." << std::endl;
//concertation
  return 0;
}
/* Output:
Enter your name:
Lilla Lilla Tóth
Lilla Lilla Tóth
Hello, Lilla, welcome to this tutorial.

Enter your name:
Hello,  Lilla Tóth, welcome to this tutorial.
 */