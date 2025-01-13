#include <format>
#include <iostream>
#include <optional>
#include <string>

std::string obenglobishize(std::string);
void obenglobishizeInPlace(std::string &);
bool isVowel(char);
void test(std::string word, std::string expected);

int main() {
  // only adds "ob" to first vowel in sequence
  test("a", "oba");
  test("aa", "obaa");
  test("aaa", "obaaa");
  test("baa", "bobaa");
  test("aab", "obaab");

  // does not add "ob" before "e" at end of word
  test("teste", "tobeste");
  test("worde", "woborde");

  // does not match cases above
  test("test", "tobest");
  test("word", "wobord");

  // edge case
  test("", "");

  // real world
  test("english", "obenglobish");

  return 0;
}

std::string obenglobishize(std::string word) {
  std::string newWord = "";
  std::optional<char> lastChar;
  for (int i = 0; i < word.length(); i++) {
    char currChar = word[i];
    if (isVowel(currChar)) {
      bool lastWasVowel = lastChar.has_value() && isVowel(lastChar.value());
      bool lastE = currChar == 'e' && i == word.length() - 1;
      if (!lastWasVowel && !lastE) newWord += "ob";
    }
    newWord += currChar;
    lastChar = currChar;
  }
  return newWord;
}

void obenglobishizeInPlace(std::string &word) {
  int i = 0;
  std::optional<char> lastChar;
  while (i < word.length()) {
    char currChar = word[i];
    if (isVowel(currChar)) {
      bool lastWasVowel = lastChar.has_value() && isVowel(lastChar.value());
      bool lastE = currChar == 'e' && i == word.length() - 1;
      if (!lastWasVowel && !lastE) {
        word.insert(i, "ob");
        i += 2;
      }
    }
    i++;
    lastChar = currChar;
  }
}

bool isVowel(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void test(std::string word, std::string expected) {
  // obenglobishize
  try {
    std::string actual = obenglobishize(word);
    if (actual != expected)
      std::cout << std::format("obenglobishize({}): expected {} but got {}",
                               word, expected, actual)
                << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // obenglobishizeInPlace
  try {
    std::string oldWord = word;
    obenglobishizeInPlace(word);
    if (word != expected)
      std::cout << std::format(
                       " obenglobishizeInPlace({}): expected {} but got {}",
                       oldWord, expected, word)
                << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}