#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

bool isSentencePalindrome(std::string str);

int main() {
  assert(isSentencePalindrome(""));
  assert(isSentencePalindrome("a"));
  assert(isSentencePalindrome("aa"));
  assert(isSentencePalindrome("aaa"));
  assert(isSentencePalindrome("aa a"));
  assert(isSentencePalindrome("a aa"));
  assert(isSentencePalindrome("a  a"));
  assert(isSentencePalindrome("a a a"));
  assert(isSentencePalindrome("ab cac ba"));
  assert(isSentencePalindrome("A a"));
  assert(isSentencePalindrome("a A"));
  assert(isSentencePalindrome("a-a"));
  assert(isSentencePalindrome("a'a"));
  assert(isSentencePalindrome("a,a"));
  assert(isSentencePalindrome("aa."));
  assert(isSentencePalindrome(".aa"));
  assert(isSentencePalindrome("---"));
  assert(isSentencePalindrome("Madam, I'm Adam."));

  assert(!isSentencePalindrome("ab"));
  assert(!isSentencePalindrome("a b"));
  assert(!isSentencePalindrome("abab"));
  assert(!isSentencePalindrome("..ab"));
  assert(!isSentencePalindrome("abbab"));

  return 0;
}

bool isSentencePalindrome(std::string str) {
  if (str.empty()) return true;

  int p1 = 0;
  int p2 = str.length() - 1;
  while (p1 < p2) {
    while (p1 < p2 && !isalpha(str[p1])) p1++;
    while (p1 < p2 && !isalpha(str[p2])) p2--;
    if (tolower(str[p1]) != tolower(str[p2])) return false;
    p1++;
    p2--;
  }

  return true;
}