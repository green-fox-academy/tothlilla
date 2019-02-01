#include <iostream>

// Given a string, compute recursively a new string where all the 'x' chars have been removed.

std::string remover(std::string strOrigin, int strOriginSize);

int main() {

  std::string str = "yzhkxyjlXxkFTZXxKKLLXYY xXx";
  int sizeStr = str.size();
  std::cout << "voala:" << remover(str, sizeStr) <<" the result" << std::endl;

  return 0;
}

std::string remover(std::string strOrigin, int strOriginSize) //definition of the function
{
  if (strOriginSize - 1 == -1) { //base case, when thr lenght of the string is zero...
    return strOrigin;            //... and it returns as a zero length string
  } else if (strOrigin[strOriginSize - 1] == 'x') {   //"base case2", at 0 index (1 char length)
    strOrigin.erase(strOriginSize-1, 1);              //useage erase (starting index number, length of characters to delete
    return remover(strOrigin, (strOriginSize - 1));
  } else {
    return remover(strOrigin, (strOriginSize - 1));
  }
}