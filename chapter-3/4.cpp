#include <cassert>
#include <cctype>
#include <iostream>

void capitalize(std::string &);
void titleize(std::string &);

int main() {
  std::string str = "";

  // capitalize
  {
    str = "";
    capitalize(str);
    assert(str == "");

    str = "test";
    capitalize(str);
    assert(str == "Test");

    str = " test ";
    capitalize(str);
    assert(str == " Test ");

    str = "Test";
    capitalize(str);
    assert(str == "Test");

    str = "TEST";
    capitalize(str);
    assert(str == "Test");
  }

  // titleize
  {
    str = "";
    titleize(str);
    assert(str == "");

    str = "test";
    titleize(str);
    assert(str == "Test");

    str = " test ";
    titleize(str);
    assert(str == " Test ");

    str = "Test";
    titleize(str);
    assert(str == "Test");

    str = "TEST";
    titleize(str);
    assert(str == "Test");

    str = "test test";
    titleize(str);
    assert(str == "Test Test");

    str = "  test  test  ";
    titleize(str);
    assert(str == "  Test  Test  ");
  }

  return 0;
}

void capitalize(std::string &str) {
  bool capitalized = false;
  for (int i = 0; i < str.length(); i++) {
    if (!isalpha(str[i])) continue;
    if (capitalized) {
      str[i] = tolower(str[i]);
    } else {
      str[i] = toupper(str[i]);
      capitalized = true;
    }
  }
}

void titleize(std::string &str) {
  bool titleizeNext = false;
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (isspace(ch)) {
      titleizeNext = true;
    } else if (i == 0 || titleizeNext) {
      str[i] = toupper(ch);
      titleizeNext = false;
    } else {
      str[i] = tolower(ch);
    }
  }
}
