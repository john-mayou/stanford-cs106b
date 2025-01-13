#include <cassert>
#include <iostream>
#include <string>

std::string addCommas(std::string);
void addCommasInPlace(std::string &);

int main() {
  // addCommas
  {
    assert(addCommas("") == "");
    assert(addCommas("10") == "10");
    assert(addCommas("100") == "100");
    assert(addCommas("1000") == "1,000");
    assert(addCommas("1000000") == "1,000,000");
    assert(addCommas("10000000") == "10,000,000");
  }

  // addCommasInPlace
  {
    std::string str;

    str = "";
    addCommasInPlace(str);
    assert(str == "");

    str = "10";
    addCommasInPlace(str);
    assert(str == "10");

    str = "100";
    addCommasInPlace(str);
    assert(str == "100");

    str = "1000";
    addCommasInPlace(str);
    assert(str == "1,000");

    str = "1000000";
    addCommasInPlace(str);
    assert(str == "1,000,000");

    str = "10000000";
    addCommasInPlace(str);
    assert(str == "10,000,000");
  }

  return 0;
}

std::string addCommas(std::string digits) {
  if (digits.empty()) return digits;

  std::string newStr = "";
  int digitsSinceComma = 0;
  for (int i = digits.length() - 1; i >= 0; i--) {
    newStr = digits[i] + newStr;
    digitsSinceComma++;
    if (digitsSinceComma == 3 && i != 0) {
      newStr = "," + newStr;
      digitsSinceComma = 0;
    }
  }

  return newStr;
}

void addCommasInPlace(std::string &digits) {
  if (digits.empty()) return;

  int i = digits.length() - 1;
  int digitsSinceComma = 0;
  while (i >= 0) {
    digitsSinceComma++;
    if (digitsSinceComma == 3 && i != 0) {
      digits.insert(i, ",");
      digitsSinceComma = 0;
    }
    i--;
  }
}