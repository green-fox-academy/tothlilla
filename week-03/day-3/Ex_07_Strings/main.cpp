#include <iostream>

// Given a string, compute recursively (no loops) a new string where all the
// lowercase 'x' chars have been changed to 'y' chars.

std::string changer(std::string strOrigin, int strOriginSize)
{
  if (strOriginSize - 1 == -1) {
    return strOrigin;
  } else if (strOrigin[strOriginSize - 1] == 'x') {
    strOrigin[strOriginSize - 1] = 'y';
    return changer(strOrigin, (strOriginSize - 1));
  } else {
    return changer(strOrigin, (strOriginSize - 1));
  }
}

int main() {

  std::string str = "yzhkxyjlXxkFTZXxKKLLXYY xXx";
  int sizeStr = str.size();

  std::cout << "voala:" <<changer(str, sizeStr) <<" the result" << std::endl;
  return 0;
}