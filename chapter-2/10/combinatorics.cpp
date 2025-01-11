#include "combinatorics.h"

int fact(int);

int combinations(int n, int k) { return permutations(n, k) / fact(k); }

int permutations(int n, int k) {
  int product = 1;
  for (int i = n - k + 1; i <= n; i++) {
    product *= i;
  }
  return product;
}

int fact(int n) {
  int product = 1;
  for (int i = 1; i <= n; i++) {
    product *= i;
  }
  return product;
}