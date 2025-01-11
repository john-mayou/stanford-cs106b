#include <iostream>

int permutations(int n, int k);

int main() {
  std::cout << permutations(52, 2)
            << " card pair permutations in a 52 card deck." << std::endl;
  return 0;
}

int permutations(int n, int k) {
  int product = 1;
  for (int i = n - k + 1; i <= n; i++) {
    product *= i;
  }
  return product;
}