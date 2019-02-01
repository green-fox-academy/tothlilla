#include <iostream>

// Given a string, compute recursively a new string where all the
// adjacent chars are now separated by a '*'.

std::string inserter(std::string strOrigin, int strOriginSize); //function predefinition

int main() {

  std::string str = "yzhkxyjlXxkFTZXxKKLLXYY xXx";
  int sizeStr = str.size();
  std::cout << "voala:" <<inserter(str, sizeStr) <<" the result" << std::endl;

  return 0;
}

std::string inserter(std::string strOrigin, int strOriginSize)
{
  if (strOriginSize - 1 == -1) { //base case when the length of the string is zero
    return strOrigin;
  } else {
    strOrigin.insert(strOriginSize, "*"); //we insert an "*" character AFTER every character (not BEFORE them, to do this, use:(strOriginSize - 1))
    return inserter(strOrigin, (strOriginSize - 1));
  }
}