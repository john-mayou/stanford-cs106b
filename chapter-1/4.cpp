#include <iostream>

int main() {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;
  int sum = 0;
  int current = 0;
  while (n > 0) {
    if (current % 2 == 1) {
      sum += current;
      n -= 1;
    }
    if (n == 0) {
      break;
    }
    current += 1;
  }
  std::cout << "Total: " << sum << std::endl;
  return 0;
}