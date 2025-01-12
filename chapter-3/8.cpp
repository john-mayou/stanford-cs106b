#include <cassert>
#include <iostream>
#include <string>

void removeCharsInPlace(std::string &str, std::string remove);

int main() {
  std::string str;

  str = "";
  removeCharsInPlace(str, "");
  assert(str == "");

  str = "";
  removeCharsInPlace(str, "test");
  assert(str == "");

  str = "test";
  removeCharsInPlace(str, "");
  assert(str == "test");

  str = "test";
  removeCharsInPlace(str, "es");
  assert(str == "tt");

  str = "test";
  removeCharsInPlace(str, "test");
  assert(str == "");

  str = "test";
  removeCharsInPlace(str, "set");
  assert(str == "");

  return 0;
}

void removeCharsInPlace(std::string &str, std::string remove) {
  if (str.empty() || remove.empty()) return;

  int i = 0;
  while (true) {
    bool removeChar = false;
    for (int j = 0; j < remove.length(); j++) {
      if (str[i] == remove[j]) {
        removeChar = true;
        break;
      }
    }

    if (removeChar) {
      str.erase(i, 1);
    } else {
      i++;
    }

    if (i == str.length()) {
      break;
    }
  }
}