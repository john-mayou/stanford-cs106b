#include "titleize.h"

#include <cctype>

namespace cpp_abstractions::titleize {
std::string titleize(const std::string& str) {
  std::string result;
  bool capitalizeNext = false;

  for (int i = 0; i < str.length(); i++) {
    char c = str[i];
    if (std::isspace(c)) {
      result += c;
      capitalizeNext = true;
    } else if (capitalizeNext || i == 0) {
      result += std::toupper(c);
      capitalizeNext = false;
    } else {
      result += std::tolower(c);
    }
  }

  return result;
}
}  // namespace cpp_abstractions::titleize