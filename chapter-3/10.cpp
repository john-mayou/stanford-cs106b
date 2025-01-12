#include <cassert>
#include <iostream>
#include <string>

std::string replaceAll(std::string str, char c1, char c2);
void replaceAllInPlace(std::string &str, char c1, char c2);

int main() {
  // replaceAll
  {
    assert(replaceAll("", 'a', 'b') == "");
    assert(replaceAll("a", 'a', 'b') == "b");
    assert(replaceAll("a", 'b', 'z') == "a");
    assert(replaceAll("aa", 'a', 'b') == "bb");
    assert(replaceAll("aabb", 'a', 'b') == "bbbb");
    assert(replaceAll("abab", 'a', 'b') == "bbbb");
  }

  // replaceAllInPlace
  {
    std::string str;

    str = "";
    replaceAllInPlace(str, 'a', 'b');
    assert(str == "");

    str = "a";
    replaceAllInPlace(str, 'a', 'b');
    assert(str == "b");

    str = "a";
    replaceAllInPlace(str, 'b', 'z');
    assert(str == "a");

    str = "aa";
    replaceAllInPlace(str, 'a', 'b');
    assert(str == "bb");

    str = "aabb";
    replaceAllInPlace(str, 'a', 'b');
    assert(str == "bbbb");

    str = "abab";
    replaceAllInPlace(str, 'a', 'b');
    assert(str == "bbbb");
  }

  return 0;
}

std::string replaceAll(std::string str, char c1, char c2) {
  if (str.empty()) return str;
  std::string newStr = "";
  for (int i = 0; i < str.length(); i++) {
    newStr += (str[i] == c1) ? c2 : str[i];
  }
  return newStr;
}

void replaceAllInPlace(std::string &str, char c1, char c2) {
  if (str.empty()) return;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == c1) str[i] = c2;
  }
}
