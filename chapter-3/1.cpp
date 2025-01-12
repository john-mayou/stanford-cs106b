#include <iostream>
#include <string>

bool endsWith(std::string str, std::string suffix);
bool endsWithManual(std::string str, std::string suffix);

int main() {
  std::cout << "endsWith(\"level\", \"el\"): "
            << (endsWith("level", "el") ? "true" : "false") << std::endl;
  std::cout << "endsWith(\"level\", \"le\"): "
            << (endsWith("level", "le") ? "true" : "false") << std::endl;

  std::cout << "endsWithManual(\"level\", \"el\"): "
            << (endsWithManual("level", "el") ? "true" : "false") << std::endl;
  std::cout << "endsWithManual(\"level\", \"le\"): "
            << (endsWithManual("level", "le") ? "true" : "false") << std::endl;

  return 0;
}

bool endsWith(std::string str, std::string suffix) {
  if (str.length() < suffix.length()) return false;
  return str.compare(str.length() - suffix.length(), suffix.length(), suffix) ==
         0;
}

bool endsWithManual(std::string str, std::string suffix) {
  if (str.length() < suffix.length()) return false;
  int offset = str.length() - suffix.length();
  for (int i = 0; i < suffix.length() - 1; i++) {
    if (str[i + offset] != suffix[i]) return false;
  }
  return true;
}