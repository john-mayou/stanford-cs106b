#include <iostream>

#include "combinatorics.h"

int main() {
  std::cout << combinations(6, 2) << " combinations in a 6 card deck."
            << std::endl;
  std::cout << permutations(52, 2) << " permutations in a 52 card deck."
            << std::endl;
  return 0;
}