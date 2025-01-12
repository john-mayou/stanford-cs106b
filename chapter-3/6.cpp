#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

std::string acronyze(std::string);

int main() {
  assert(acronyze("") == "");
  assert(acronyze("test") == "T");
  assert(acronyze("test test") == "TT");
  assert(acronyze("  test  test  ") == "TT");
  assert(acronyze("  t  t  ") == "TT");
  assert(acronyze("-test-test-") == "TT");
  assert(acronyze("self-contained underwater breathing apparatus") == "SCUBA");

  return 0;
}

std::string acronyze(std::string str) {
  std::string acronym = "";
  bool lastWasSpace = false;
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (!isalpha(ch)) {
      lastWasSpace = true;
    } else if (i == 0 || lastWasSpace) {
      acronym += toupper(ch);
      lastWasSpace = false;
    }
  }
  return acronym;
}