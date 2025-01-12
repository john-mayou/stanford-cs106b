#include <cctype>
#include <format>
#include <iostream>
#include <string>

std::string trim(std::string);
std::string trimInPlace(std::string);

int main() {
  std::cout << std::format("trim(\"\"): '{}'", trim("")) << std::endl;
  std::cout << std::format("trim(\"hello\"): '{}'", trim("hello")) << std::endl;
  std::cout << std::format("trim(\" hello\"): '{}'", trim(" hello"))
            << std::endl;
  std::cout << std::format("trim(\"hello \"): '{}'", trim("hello "))
            << std::endl;
  std::cout << std::format("trim(\" hello \"): '{}'", trim(" hello "))
            << std::endl;
  std::cout << std::format("trim(\" hello \"): '{}'", trim(" hello "))
            << std::endl;
  std::cout << std::format("trim(\"\\thello\\n\"): '{}'", trim("\thello\n"))
            << std::endl;
  return 0;
}

std::string trim(std::string str) {
  std::string newStr = "";
  for (int i = 0; i < str.length(); i++) {
    if (!std::isspace(str[i])) newStr += str[i];
  }
  return newStr;
}

std::string trimInPlace(std::string &str) {
  for (int i = 0; i < str.length(); i++) {
    if (std::isspace(str[i])) str.erase(i, 1);
  }
  return str;
}