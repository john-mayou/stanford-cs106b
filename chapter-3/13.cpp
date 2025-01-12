#include <cassert>
#include <iostream>
#include <string>

std::string createOrdinalForm(int n);

int main() {
  assert(createOrdinalForm(0) == "0th");
  assert(createOrdinalForm(1) == "1st");
  assert(createOrdinalForm(2) == "2nd");
  assert(createOrdinalForm(3) == "3rd");
  assert(createOrdinalForm(4) == "4th");
  assert(createOrdinalForm(11) == "11th");
  assert(createOrdinalForm(12) == "12th");
  assert(createOrdinalForm(13) == "13th");
  assert(createOrdinalForm(21) == "21st");
  assert(createOrdinalForm(22) == "22nd");
  assert(createOrdinalForm(23) == "23rd");
  assert(createOrdinalForm(24) == "24th");
  assert(createOrdinalForm(100) == "100th");
  assert(createOrdinalForm(111) == "111th");
  assert(createOrdinalForm(112) == "112th");
  assert(createOrdinalForm(113) == "113th");
  assert(createOrdinalForm(121) == "121st");
  assert(createOrdinalForm(122) == "122nd");
  assert(createOrdinalForm(123) == "123rd");
  assert(createOrdinalForm(124) == "124th");
  assert(createOrdinalForm(-1) == "-1st");

  return 0;
}

std::string createOrdinalForm(int n) {
  std::string nStr = std::to_string(n);
  n = n < 0 ? -n : n;  // normalize

  int lastDigit = n % 10;
  int lastTwoDigits = n % 100;

  if (lastTwoDigits >= 11 && lastTwoDigits <= 13) {
    return nStr + "th";
  }

  switch (lastDigit) {
    case 1:
      return nStr + "st";
    case 2:
      return nStr + "nd";
    case 3:
      return nStr + "rd";
    default:
      return nStr + "th";
  }
}