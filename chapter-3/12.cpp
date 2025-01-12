#include <cassert>
#include <iostream>
#include <string>

std::string convertPlural(std::string);
bool endsWith(std::string str, std::string suffix);

int main() {
  // ending in s, x, z, ch, sh
  assert(convertPlural("class") == "classes");
  assert(convertPlural("box") == "boxes");
  assert(convertPlural("quiz") == "quizes");
  assert(convertPlural("match") == "matches");
  assert(convertPlural("brush") == "brushes");

  // ending in y preceded by a consonant
  assert(convertPlural("baby") == "babies");
  assert(convertPlural("lady") == "ladies");
  assert(convertPlural("city") == "cities");
  assert(convertPlural("party") == "parties");

  // ending in y preceded by a vowel
  assert(convertPlural("toy") == "toys");
  assert(convertPlural("key") == "keys");
  assert(convertPlural("day") == "days");
  assert(convertPlural("monkey") == "monkeys");

  // that don't fit the above rules
  assert(convertPlural("car") == "cars");
  assert(convertPlural("dog") == "dogs");
  assert(convertPlural("apple") == "apples");

  // edge cases
  assert(convertPlural("") == "");
  assert(convertPlural("y") == "ys");  // no consonant preceding y

  return 0;
}

std::string convertPlural(std::string word) {
  if (word.empty()) return word;

  if (endsWith(word, "s") || endsWith(word, "x") || endsWith(word, "z") ||
      endsWith(word, "ch") || endsWith(word, "sh")) {
    return word + "es";
  }

  if (endsWith(word, "y") && word.length() > 1) {
    char preceding = word[word.length() - 2];
    switch (preceding) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        break;
      default:
        word[word.length() - 1] = 'i';
        return word + "es";
    }
  }

  return word + "s";
}

bool endsWith(std::string str, std::string suffix) {
  if (str.length() < suffix.length()) return false;

  int strIdxStart = str.length() - suffix.length();
  for (int i = 0; i < suffix.length(); i++) {
    if (str[strIdxStart + i] != suffix[i]) return false;
  }

  return true;
}