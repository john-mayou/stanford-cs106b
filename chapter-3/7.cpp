#include <cassert>
#include <iostream>
#include <string>

std::string removeChars(std::string str, std::string remove);
void removeCharsInPlace(std::string &str, std::string remove);

int main() {
  // removeChars
  {
    assert(removeChars("", "") == "");
    assert(removeChars("", "test") == "");
    assert(removeChars("test", "") == "test");
    assert(removeChars("test", "es") == "tt");
    assert(removeChars("test", "test") == "");
    assert(removeChars("test", "sett") == "");
  }

  // removeCharsInPlace
  {
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
    removeCharsInPlace(str, "sett");
    assert(str == "");
  }

  return 0;
}

std::string removeChars(std::string str, std::string remove) {
  std::string newStr = "";
  for (int i = 0; i < str.length(); i++) {
    bool addCh = true;
    for (int j = 0; j < remove.length(); j++) {
      if (str[i] == remove[j]) {
        addCh = false;
        break;
      }
    }
    if (addCh) newStr += str[i];
  }
  return newStr;
}

void removeCharsInPlace(std::string &str, std::string remove) {
  if (str.empty() || remove.empty()) return;

  int i = 0;
  while (true) {
    bool removeCh = false;
    for (int j = 0; j < remove.length(); j++) {
      if (str[i] == remove[j]) {
        removeCh = true;
        break;
      }
    }

    if (removeCh) {
      str.erase(i, 1);
    } else {
      i++;
    }

    if (i == str.length()) {
      break;
    }
  }
}