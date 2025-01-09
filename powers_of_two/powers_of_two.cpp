#include <iostream>

int raiseToPower(int n, int k);

int main() {
  int limit;
  std::cout << "This program lists powers of two." << std::endl;
  std::cout << "Enter exponent limit: ";
  std::cin >> limit;
  for (int i = 0; i <= limit; i++) {
    std::cout << "2 to the " << i << " = " << raiseToPower(2, i) << std::endl;
  }
  return 0;
}

int raiseToPower(int n, int k) {
  int result = 1;
  for (int i = 0; i < k; i++) {
    result *= n;
  }
  return result;
}