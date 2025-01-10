#include <iostream>

int main() {
  int n;
  std::cout << "This program demonstrates the hailstone sequence." << std::endl;
  std::cout << "Enter a number: ";
  std::cin >> n;

  while (true) {
    if (n == 1) {
      break;
    } else if (n % 2 == 0) {
      std::cout << n << " is even, so I divide it by 2 to get ";
      n /= 2;
      std::cout << n << std::endl;
    } else if (n % 2 == 1) {
      std::cout << n << " is odd, so I multiply by 3 and add 1 to get ";
      n = n * 3 + 1;
      std::cout << n << std::endl;
    }
  }

  return 0;
}