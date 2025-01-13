#include <cassert>
#include <iostream>
#include <string>

int findDNAMatch(std::string s1, std::string s2, int start = 0);

int main() {
  assert(findDNAMatch("TAACGGTACGTC", "TTGCC") == 1);
  assert(findDNAMatch("TAACGGTACGTC", "TGC") == 2);
  assert(findDNAMatch("TAACGGTACGTC", "TGC", 3) == 7);

  return 0;
}

int findDNAMatch(std::string s1, std::string s2, int start) {
  for (int i = start; i < s1.length(); i++) {
    for (int j = 0; j < s2.length(); j++) {
      char s1Ch = s1[i + j];
      char s2Ch = s2[j];
      bool match = false;
      switch (s1Ch) {
        case 'A':
          match = s2Ch == 'T';
          break;
        case 'C':
          match = s2Ch == 'G';
          break;
        case 'G':
          match = s2Ch == 'C';
          break;
        case 'T':
          match = s2Ch == 'A';
          break;
        default:
          throw std::invalid_argument("s1 must only contain A, C, G or T: " +
                                      std::string(1, s1Ch));
      }
      if (!match) break;
      if (j == s2.length() - 1) return i;
    }
  }
  return -1;
}