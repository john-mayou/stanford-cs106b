#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

std::string encodeCaesarCipher(std::string str, int shift);

int main() {
  // single letter shift
  assert(encodeCaesarCipher("a", 0) == "a");
  assert(encodeCaesarCipher("A", 0) == "A");
  assert(encodeCaesarCipher("a", 1) == "b");
  assert(encodeCaesarCipher("A", 1) == "B");
  assert(encodeCaesarCipher("a", -1) == "z");
  assert(encodeCaesarCipher("A", -1) == "Z");
  assert(encodeCaesarCipher("a", -26) == "a");
  assert(encodeCaesarCipher("A", -26) == "A");

  // mutiple letter shift
  assert(encodeCaesarCipher("abcdefghijklmnopqrstuvwxyz", 1) ==
         "bcdefghijklmnopqrstuvwxyza");
  assert(encodeCaesarCipher("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1) ==
         "BCDEFGHIJKLMNOPQRSTUVWXYZA");

  // non alpha
  assert(encodeCaesarCipher("0123456789", 1) == "0123456789");
  assert(encodeCaesarCipher("-.,|<>-+=", 1) == "-.,|<>-+=");
  assert(encodeCaesarCipher(" ", 1) == " ");

  // edge case
  assert(encodeCaesarCipher("", -1) == "");
  assert(encodeCaesarCipher("", 0) == "");
  assert(encodeCaesarCipher("", 1) == "");

  // real world
  assert(encodeCaesarCipher("This is a secret message.", 13) ==
         "Guvf vf n frperg zrffntr.");
  assert(encodeCaesarCipher("IBM 9000", -1) == "HAL 9000");

  return 0;
}

const std::string aLower = "abcdefghijklmnopqrstuvwxyz";
const std::string aUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int aLen = 26;

std::string encodeCaesarCipher(std::string str, int shift) {
  shift = shift % aLen + aLen;  // ensure positive
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (isalpha(ch)) {
      if (islower(ch)) {
        str[i] = aLower[(aLower.find(ch) + shift) % aLen];
      } else {
        str[i] = aUpper[(aUpper.find(ch) + shift) % aLen];
      }
    }
  }
  return str;
}