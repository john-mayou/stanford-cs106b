#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

std::string lineToPigLatin(std::string);
std::string wordToPigLatin(std::string);
std::string capitalize(std::string);
int findFirstVowel(std::string);

int main() {
  // no vowel
  assert(lineToPigLatin("bcdfghjklmnpqrstvwxyx") == "bcdfghjklmnpqrstvwxyx");
  assert(lineToPigLatin("Bcdfghjklmnpqrstvwxyx") == "Bcdfghjklmnpqrstvwxyx");

  // start with vowel
  assert(lineToPigLatin("acorn") == "acornway");
  assert(lineToPigLatin("even") == "evenway");
  assert(lineToPigLatin("iglo") == "igloway");
  assert(lineToPigLatin("open") == "openway");
  assert(lineToPigLatin("uno") == "unoway");
  assert(lineToPigLatin("Acorn") == "Acornway");

  // start with consonant with vowel later
  assert(lineToPigLatin("test") == "esttay");
  assert(lineToPigLatin("word") == "ordway");
  assert(lineToPigLatin("test word") == "esttay ordway");
  assert(lineToPigLatin("Test Word") == "Esttay Ordway");

  // edge case
  assert(lineToPigLatin("") == "");

  // real world
  assert(lineToPigLatin("This is Pig Latin") == "Isthay isway Igpay Atinlay");

  return 0;
}

std::string lineToPigLatin(std::string line) {
  if (line.empty()) return line;

  std::string newLine = "";

  int wordStart = -1;
  for (int i = 0; i < line.length(); i++) {
    char ch = line[i];
    if (isalpha(ch)) {
      if (wordStart == -1) wordStart = i;
    } else {
      if (wordStart >= 0) {
        newLine += wordToPigLatin(line.substr(wordStart, i - wordStart));
        wordStart = -1;
      }
      newLine += ch;
    }
  }

  if (wordStart >= 0) {
    newLine += wordToPigLatin(line.substr(wordStart));
  }

  return newLine;
}

std::string wordToPigLatin(std::string word) {
  int firstVowel = findFirstVowel(word);
  switch (firstVowel) {
    case -1:
      return word;
    case 0:
      return word + "way";
    default:
      std::string newWord =
          word.substr(firstVowel) + word.substr(0, firstVowel) + "ay";
      return isupper(word[0]) ? capitalize(newWord) : newWord;
  }
}

std::string capitalize(std::string word) {
  for (int i = 0; i < word.length(); i++) {
    word[i] = (i == 0) ? toupper(word[i]) : tolower(word[i]);
  }
  return word;
}

int findFirstVowel(std::string word) {
  for (int i = 0; i < word.length(); i++) {
    char ch = tolower(word[i]);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
      return i;
    }
  }
  return -1;
}