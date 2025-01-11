#include <iostream>

const int rangeMin = 1;
const int rangeMax = 100;

bool isPrime(int n);

int main() {
  std::cout << "Prime numbers:" << std::endl;
  for (int i = rangeMin; i <= rangeMax; i++) {
    if (isPrime(i)) std::cout << i << std::endl;
  }
  return 0;
}

bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}