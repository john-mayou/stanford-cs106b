#include <iostream>

bool isPrime(int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  std::cout << "This program factors a number." << std::endl;
  std::cout << "Enter number to be factored: ";
  std::cin >> n;

  bool isFirst = true;
  int current = 2;
  while (n != 1) {
    if (n % current == 0) {
      if (isFirst) {
        std::cout << current;
        isFirst = false;
      } else {
        std::cout << " x " << current;
      }
      n /= current;
    } else {
      current++;
      while (!isPrime(current)) current++;
    }
  }
  std::cout << std::endl;

  return 0;
}