#include <cassert>
#include <cctype>
#include <cerrno>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

std::string greekify(std::string str);
char randChar(std::string str);

const std::string UPPER_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string LOWER_ALPHABET = "abcdefghijklmnopqrstuvwxyz";

int main() {
  std::string test = "Test Sentence";
  std::string actual = greekify(test);

  std::cout << "test: " << test << std::endl;
  std::cout << "actual: " << actual << std::endl;

  return 0;
}

std::string greekify(std::string str) {
  std::string greek(str.length(), '\0');
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (isalpha(ch)) {
      if (isupper(ch)) {
        greek[i] = randChar(UPPER_ALPHABET);
      } else {
        greek[i] = randChar(LOWER_ALPHABET);
      }
    } else {
      greek[i] = ch;
    }
  }
  return greek;
}

char randChar(std::string str) {
  double p = rand() / (double(RAND_MAX) + 1);  // normalize
  double s = p * str.length();                 // scale
  return str[std::floor(s)];
}