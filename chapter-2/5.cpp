#include <iostream>

const int rangeMin = 1;
const int rangeMax = 9999;

bool isPerfect(int n);

int main() {
  std::cout << "Perfect numbers:" << std::endl;
  for (int i = rangeMin; i <= rangeMax; i++) {
    if (isPerfect(i)) std::cout << i << std::endl;
  }
  return 0;
}

bool isPerfect(int n) {
  int sum = 0;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) sum += i;
  }
  return sum == n;
}