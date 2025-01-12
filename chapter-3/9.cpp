#include <cassert>
#include <iostream>
#include <optional>
#include <string>

std::string removeRepeatChars(std::string);
void removeRepeatCharsInPlace(std::string &);

int main() {
  // removeRepeatChars
  {
    assert(removeRepeatChars("") == "");
    assert(removeRepeatChars("a") == "a");
    assert(removeRepeatChars("aa") == "a");
    assert(removeRepeatChars("aaa") == "a");
    assert(removeRepeatChars("aabb") == "ab");
    assert(removeRepeatChars("aabbaa") == "aba");
  }

  // removeRepeatCharsInPlace
  {
    std::string str;

    str = "";
    removeRepeatCharsInPlace(str);
    assert(str == "");

    str = "a";
    removeRepeatCharsInPlace(str);
    assert(str == "a");

    str = "aa";
    removeRepeatCharsInPlace(str);
    assert(str == "a");

    str = "aaa";
    removeRepeatCharsInPlace(str);
    assert(str == "a");

    str = "aabb";
    removeRepeatCharsInPlace(str);
    assert(str == "ab");

    str = "aabbaa";
    removeRepeatCharsInPlace(str);
    assert(str == "aba");
  }

  return 0;
}

std::string removeRepeatChars(std::string str) {
  std::string newStr = "";
  std::optional<char> lastCh;
  for (int i = 0; i < str.length(); i++) {
    if (!lastCh.has_value() || lastCh != str[i]) {
      newStr += str[i];
    }
    lastCh = str[i];
  }
  return newStr;
}

void removeRepeatCharsInPlace(std::string &str) {
  if (str.empty()) return;

  int i = 0;
  std::optional<char> lastCh;
  while (true) {
    char currCh = str[i];
    if (lastCh.has_value() && lastCh == currCh) {
      str.erase(i, 1);
    } else {
      i++;
    }
    lastCh = currCh;

    if (i == str.length()) {
      break;
    }
  }
}