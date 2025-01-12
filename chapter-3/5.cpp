#include <cassert>
#include <iostream>
#include <string>

int scrabble(std::string);

int main() {
  assert(scrabble("ABCDE") == 10);
  assert(scrabble("FGHIJ") == 19);
  assert(scrabble("KLMNO") == 11);
  assert(scrabble("PQRST") == 16);
  assert(scrabble("UVWXY") == 21);
  assert(scrabble("ZABCD") == 19);
  assert(scrabble("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 87);
  assert(scrabble("abcdefghijklmnopqrstuvwxyz") == 0);

  std::string word;
  std::cout << "Enter a word: ";
  getline(std::cin, word);
  std::cout << "Score: " << scrabble(word) << std::endl;

  return 0;
}

int scrabble(std::string str) {
  int score = 0;
  for (int i = 0; i < str.length(); i++) {
    switch (str[i]) {
      case 'A':
      case 'E':
      case 'I':
      case 'L':
      case 'N':
      case 'O':
      case 'R':
      case 'S':
      case 'T':
      case 'U':
        score += 1;
        break;
      case 'D':
      case 'G':
        score += 2;
        break;
      case 'B':
      case 'C':
      case 'M':
      case 'P':
        score += 3;
        break;
      case 'F':
      case 'H':
      case 'V':
      case 'W':
      case 'Y':
        score += 4;
        break;
      case 'K':
        score += 5;
        break;
      case 'J':
      case 'X':
        score += 8;
        break;
      case 'Q':
      case 'Z':
        score += 10;
        break;
      default:
        continue;
    }
  }
  return score;
}