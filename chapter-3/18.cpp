#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

const std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string alphaKey = "QWERTYUIOPASDFGHJKLZXCVBNM";

std::string encrypt(std::string str, std::string key = alphaKey);
std::string decrypt(std::string str, std::string key = alphaKey);

int main() {
  std::string message = "WORKERS OF THE WORLD UNITE!";
  std::string encoded = encrypt(message);
  std::string decoded = decrypt(encoded);
  assert(message != encoded);
  assert(message == decoded);

  return 0;
}

std::string encrypt(std::string str, std::string key) {
  for (int i = 0; i < str.length(); i++) {
    if (isalpha(str[i])) str[i] = key[alpha.find(str[i])];
  }
  return str;
}

std::string decrypt(std::string str, std::string key) {
  for (int i = 0; i < str.length(); i++) {
    if (isalpha(str[i])) str[i] = alpha[key.find(str[i])];
  }
  return str;
}