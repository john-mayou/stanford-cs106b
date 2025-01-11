#include <cmath>
#include <iostream>

int main() {
  int n;
  std::cout << "This program reverses the digits in an integer." << std::endl;
  std::cout << "Enter a positive integer: ";
  std::cin >> n;

  int r = 0;
  int degree =
      int(std::log10(n));  // find maximum degree (9423 -> 10^3.97 -> 3)
  while (n > 0) {
    r += (n % 10) * std::pow(10, degree);
    n /= 10;
    degree--;
  }

  std::cout << "Reversed: " << r << std::endl;
  return 0;
}