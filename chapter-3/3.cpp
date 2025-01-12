#include <iostream>
#include <string>

std::string substr(std::string str, int pos, int n = -1);

int main() {
  std::cout << "substr(\"level\", 1): " << substr("level", 1) << std::endl;
  std::cout << "substr(\"level\", 2): " << substr("level", 2) << std::endl;
  std::cout << "substr(\"level\", 2, 2): " << substr("level", 2, 2)
            << std::endl;
  std::cout << "substr(\"level\", 2, 5): " << substr("level", 2, 5)
            << std::endl;

  // invalid args
  std::cout << "substr(\"level\", 2, 5): ";
  try {
    substr("level", 10);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

std::string substr(std::string str, int pos, int n) {
  if (pos > str.length() - 1)
    throw std::invalid_argument("pos index must a valid index within str");

  if (n == -1 || n > str.length() - pos) {
    n = str.length() - pos;
  }

  std::string newStr = "";
  for (int i = 0; i < n; i++) {
    newStr += str[pos + i];
  }

  return newStr;
}