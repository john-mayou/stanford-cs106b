#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

std::string invertKey(std::string key);

const std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string encryptKey = "QWERTYUIOPASDFGHJKLZXCVBNM";
const std::string decryptKey = invertKey(encryptKey);

std::string convert(std::string str, std::string key);

int main() {
  std::string message = "SECRET MESSAGE!";
  std::string encoded = convert(message, encryptKey);
  std::string decoded = convert(encoded, decryptKey);
  assert(message != encoded);
  assert(message == decoded);

  return 0;
}

std::string invertKey(std::string key) {
  std::string newKey(key.length(), ' ');
  for (int i = 0; i < key.length(); i++) {
    newKey[key[i] - 'A'] = alpha[i];
  }
  return newKey;
}

std::string convert(std::string str, std::string key) {
  for (int i = 0; i < str.length(); i++) {
    if (isalpha(str[i])) str[i] = key[str[i] - 'A'];
  }
  return str;
}